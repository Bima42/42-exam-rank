#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

void exitError(char* str)
{
    write(1, &str, strlen(str));
    exit(1);
}

int main (int argc, char **argv)
{
    (void)argv;
    if (argc != 2)
        exitError("Wrong number of arguments\n");
    return 0;
}