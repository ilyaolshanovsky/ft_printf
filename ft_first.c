#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	width_int(int d)
{
	int	i;
	int	len;

	i = 1;
	len = 0;
	if (d == 0)
		return (1);
	if (d < 0)
	{
		d = -d;
		len = 1;
	}
	while (d / 10)
	{
		i++;
		d = d / 10;
	}
	return (i + len);
}

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int	output_point(unsigned long b)
{
	int	len;

	len = 0;
	ft_putstr("0x");
	len = 2;
	if (b == 0)
	{
		ft_putchar('0');
		len += 1;
	}
	else
	{
		ft_code(b, 16, HEX_BASE_LOW);
		len += len_un_l(b);
	}
	return (len);
}
