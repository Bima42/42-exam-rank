#include <unistd.h>
#include <stdbool.h>

void	ft_inter(char *str1, char *str2)
{
	int	i = 0;
	int tab[128] = {0};

	while (str2[i])
	{
		if (tab[(int)str2[i]] == 0)
			tab[(int)str2[i]] = 1;
		i++;
	}
	i = 0;
	while (str1[i] != '\0')
	{
		if (tab[(int)str1[i]] == 1)
		{
			tab[(int)str1[i]] = 2;
			write(1, &str1[i], 1);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
