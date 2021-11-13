#include "ft_printf.h"

int	output_int(int a)
{
	int	len;

	len = 0;
	ft_putnbr(a);
	len = width_int(a);
	return (len);
}

int	output_char(int	a)
{
	ft_putchar(a);
	return (1);
}

int	output_str(char *str)
{
	int		i;
	char	*s;

	s = NULL;
	i = 0;
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

int	output_un_int(unsigned int a)
{
	int	len;

	len = 0;
	len = width_int_un(a);
	ft_putnbr_un(a);
	return (len);
}

int	output_x_int(unsigned int a)
{
	int	len;

	len = 0;
	if (a == 0)
	{
		ft_putchar('0');
		len = 1;
	}
	ft_code(a, 16, HEX_BASE_LOW);
	len += len_un_l(a);
	return (len);
}
