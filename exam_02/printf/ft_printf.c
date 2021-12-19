#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c, int *char_write)
{
	write(1, &c, 1);
	*char_write += 1;
}

void	ft_putstr(char *str, int *char_write)
{
	while (*str)
	{
		ft_putchar(*str, char_write);
		*str++;
	}
}

void	ft_putnbr(int nb, int *char_write)
{
	unsigned int n;

	if (nb < 0)
	{
		ft_putchar('-', char_write);
		n = (unsigned int)nb * -1;
	}
	else
		n = (unsigned int)nb;
	if (n >= 10)
	{
		ft_putnbr(n / 10, char_write);
		ft_putnbr(n % 10, char_write);
	}
	else
		ft_putchar(n + '0', char_write);
}

void	ft_putnbr_hexa(unsigned long nb, char *base, int *char_write)
{
	int	base_size;

	base_size = 16;
	if (nb >= base_size)
	{
		ft_putnbr_hexa(nb / base_size, base, char_write);
		ft_putnbr_hexa(nb % base_size, base, char_write);
	}
	else
		ft_putchar(base[nb], char_write);
}

int	detect_type(va_list arg, const char *str, int i)
{
	int char_write = 0;

	if (str[i] == 's')
		ft_putstr(va_arg(arg, char *), &char_write);
	else if (str[i] == 'd')
		ft_putnbr(va_arg(arg, int), &char_write);
	else if (str[i] == 'x')
		ft_putnbr_hexa(va_arg(arg, unsigned long), "0123456789abcdef", &char_write);
	return (char_write);
}

int ft_printf(const char *str, ...)
{
	va_list	arg;
	int	i = 0;
	int	ret = 0;

	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			ret += detect_type(arg, str, ++i) - 1;
		else
			ft_putchar(str[i], &ret);
		i++;
	}
	va_end(arg);
	return (ret);
}

int main()
{
	int i;

	i = ft_printf("Salut je suis %s, j'aime le numéro %d qui s'écrit %x en hexa\n", "Tanguy", 42, 42);
	printf("%d\n", i);
}
