#include <unistd.h>
#include <stdbool.h>

bool	is_in_str(bool *tab, int c)
{
	if (tab[c] == false)
	{
		tab[c] = true;
		return (false);
	}
	return (true);
}

void	ft_union(char *str1, char *str2)
{
	bool tab[128] = {0};

	while (*str1 != '\0')
	{
		if (!is_in_str(tab, *str1))
			write(1, &*str1, 1);
		str1++;
	}
	while (*str2 != '\0')
	{
		if (!is_in_str(tab, *str2))
			write(1, &*str2, 1);
		str2++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		ft_union(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}
