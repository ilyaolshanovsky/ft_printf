#include "ft_printf.h"

int	output_X_int(unsigned int a)
{
	int	len;

	len = 0;
	if (a == 0)
	{
		ft_putchar('0');
		len = 1;
	}
	ft_code(a, 16, HEX_BASE_UP);
	len += len_un_l(a);
	return (len);
}

int	output_var(int type, va_list *var)
{
	int	len;

	len = 0;
	if (type == 'd' || type == 'i')
		len = output_int(va_arg(*var, int));
	else if (type == 'c')
		len = output_char(va_arg(*var, int));
	else if (type == 's')
		len = output_str(va_arg(*var, char *));
	else if (type == 'u')
		len = output_un_int(va_arg(*var, unsigned int));
	else if (type == 'x')
		len = output_x_int(va_arg(*var, unsigned int));
	else if (type == 'X')
		len = output_X_int(va_arg(*var, unsigned int));
	else if (type == 'p')
		len = output_point(va_arg(*var, unsigned long int));
	else if (type == '%')
	{
		ft_putchar('%');
		len = 1;
	}
	return (len);
}

int	ft_printf(const char *input, ...)
{
	int		len;
	int		i;
	va_list	var;

	if (!input)
		return (0);
	len = 0;
	i = 0;
	va_start (var, input);
	while (input[i])
	{
		if (input[i] == '%')
		{
			len += output_var(input[i + 1], &var);
			i++;
		}
		else
		{
			ft_putchar(input[i]);
			len++;
		}
		i++;
	}
	va_end(var);
	return (len);
}
