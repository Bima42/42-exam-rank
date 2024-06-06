#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	get_next_line(char **line, int fd)
{
	int i, ret, l;
	char c;
	char *tmp;

	l = 1;
	ret = 0;
	if (!(*line = malloc(1 * sizeof(char))))
		return (-1);
	(*line)[0] = '\0';
	while ((ret = read(fd, &c, 1)) && l++ && c != '\n')
	{
		if (!(tmp = malloc(1 * sizeof(char))))
			{
				free(*line);
				return (-1);
			}
		i = -1;
		while (++i < l - 2)
			tmp[i] = (*line)[i];
		tmp[i] = c;
		tmp[i + 1] = '\0';
		free(*line);
		*line = tmp;
	}
	return (ret);
}

int main(int argc, char **argv)
{
	char *s;
	int fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	printf("%d\n", get_next_line(&s, fd));
	printf("%d\n", get_next_line(&s, fd));
	printf("%d\n", get_next_line(&s, fd));
	printf("%d\n", get_next_line(&s, fd));
	printf("%d\n", get_next_line(&s, fd));
}
