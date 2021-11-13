#include "ft_printf.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write (1, "-", 1);
			n = -n;
			ft_putnbr(n);
		}
		else if (n < 10 && n >= 0)
			ft_putchar(n + '0');
		else
		{
			ft_putnbr(n / 10);
			ft_putchar((n % 10) + '0');
		}
	}
}

void	ft_putnbr_un(unsigned int n)
{
	if (n < 10 && n >= 0)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

int	len_un_l(unsigned long a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a / 16;
		i++;
	}
	return (i);
}

int	width_int_un(unsigned int d)
{
	int	i;

	if (d == 0)
		return (1);
	i = 1;
	while (d / 10)
	{
		i++;
		d = d / 10;
	}
	return (i);
}

void	ft_code(unsigned long p, int base, char *base_str)
{
	if (p)
	{
		ft_code(p / base, base, base_str);
		ft_putchar(base_str[p % base]);
	}
}
