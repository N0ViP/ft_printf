#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		j;
	int		tmp;
	int		count;

	i = 0;
	count = 0;
	while (format[i])
	{
		j =0;
		if (formate[i] != '%')
		{
			count++;
			write(1, &format[i], 1);
		}
		else
		{
			j = ft_get_flags(&format, flags);
			if (ft_chrstr("csuidxXp%", format[i + j]))
			{
				i += j;
				tmp = ft_select_type(format[i], flags);
			}
			else
			{
				count++;
				write(1, &format[i++], 1);
			}
		}
	}
}
