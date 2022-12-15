#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct client {
    int id;
    char msg[100000];
} t_client;

t_client clients[1024];

int max = 0, next_id = 0;
fd_set active, readyRead, readyWrite;
char bufRead[424242], bufWrite[424242];

void exitError(char *str)
{
    if (str)
        write(2, str, strlen(str));
    exit(1);
}

void sendAll(int es)
{
    for(int i = 0; i <= max; i++)
    {
        if (FD_ISSET(i, &readyWrite) && i != es)
            send(i, bufWrite, strlen(bufWrite), 0);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        exitError("Wrong number of arguments\n");
    int port = atoi(argv[1]);

    int serverSock = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSock < 0)
        exitError("Fatal error\n");

    bzero(clients, sizeof(clients));
    FD_ZERO(&active);

    max = serverSock;
    FD_SET(serverSock, &active);

    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = (1 << 24) + 127; // "127.0.0.1", in network order
    addr.sin_port = htons(port);

    if ((bind(serverSock, (const struct sockaddr *)&addr, sizeof(addr))) < 0)
        exitError("Fatal error\n");
    if (listen(serverSock, 128) < 0)
        exitError("Fatal error\n");

    while(1)
    {
        readyRead = readyWrite = active;
        if (select(max + 1, &readyRead, &readyWrite, NULL, NULL) < 0)
            continue;

        for(int fd = 0; fd <= max; fd++)
        {
            if (FD_ISSET(fd, &readyRead) && fd == serverSock)
            {
                int clientSocket = accept(serverSock, (struct sockaddr *)&addr, &addr_len);
                if (clientSocket < 0)
                    continue;
                max = (clientSocket > max) ? clientSocket : max;
                clients[clientSocket].id = next_id++;
                FD_SET(clientSocket, &active);
                sprintf(bufWrite, "server: client %d just arrived\n", clients[clientSocket].id);
                sendAll(clientSocket);
                break;
            }
            if (FD_ISSET(fd, &readyRead) && fd != serverSock)
            {
                int read = recv(fd, bufRead, 424242, 0);
                if (read <= 0)
                {
                    sprintf(bufWrite, "server: client %d just left\n", clients[fd].id);
                    sendAll(fd);
                    FD_CLR(fd, &active);
                    close(fd);
                    break;
                }
                else
                {
                    for (int i = 0, j = strlen(clients[fd].msg); i < read; i++, j++)
                    {
                        clients[fd].msg[j] = bufRead[i];
                        if (clients[fd].msg[j] == '\n')
                        {
                            clients[fd].msg[j] = '\0';
                            sprintf(bufWrite, "client %d: %s\n", clients[fd].id, clients[fd].msg);
                            sendAll(fd);
                            bzero(&clients[fd].msg, strlen(clients[fd].msg));
                            j = -1;
                        }
                    }
                    break;
                }
            }
        }
    }
}