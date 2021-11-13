#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>

# define HEX_BASE_LOW "0123456789abcdef"
# define HEX_BASE_UP "0123456789ABCDEF"

void	ft_putchar(char c);
size_t	ft_strlen(const char *str);
int		width_int(int d);
void	ft_putstr(char *str);
int		output_X_int(unsigned int a);
int		output_point(unsigned long b);
int		output_var(int type, va_list *var);
int		ft_printf(const char *input, ...);
void	ft_putnbr(int n);
void	ft_putnbr_un(unsigned int n);
int		len_un_l(unsigned long a);
int		width_int_un(unsigned int d);
void	ft_code(unsigned long p, int base, char *base_str);
int		output_int(int a);
int		output_char(int a);
int		output_str(char *str);
int		output_un_int(unsigned int a);
int		output_x_int(unsigned int a);

#endif
