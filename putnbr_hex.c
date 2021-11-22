#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c, int *count)
{
	write(STDOUT_FILENO, &c, sizeof(char));
	*count += 1;
}

int	ft_strlen(char *str)
{
	int i = 0;

	while (*str++)
		i++;
	return (i);
}

void	putnbr_hexa(unsigned int nb, char *base)
{
	unsigned int	base_size;
	int	count = 0;

	base_size = ft_strlen(base);
	if (nb >= base_size)
	{
		putnbr_hexa(nb / base_size, base);
		putnbr_hexa(nb % base_size, base);
	}
	else
		ft_putchar(base[nb], &count);
}

int main()
{
	putnbr_hexa(21845, "0123456789abcdef");
	return (0);
}
