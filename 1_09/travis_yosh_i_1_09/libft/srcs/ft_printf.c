/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 20:17:04 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/10 17:00:24 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_format_eval(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_printf_print_char(va_arg(args, int));
	else if (format == 'd' || format == 'i')
		len += ft_printf_print_int(va_arg(args, int));
	else if (format == 'u')
		len += ft_printf_print_u_int(va_arg(args, unsigned int));
	else if (format == 's')
		len += ft_printf_print_str(va_arg(args, char *));
	else if (format == 'X' || format == 'x')
		len += ft_printf_print_hex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		len += ft_printf_print_pointer(va_arg(args, unsigned long long));
	else if (format == '%')
		len += ft_printf_print_pcent();
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		total_length;

	va_start(args, format);
	i = 0;
	total_length = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			total_length += ft_format_eval(args, format[i + 1]);
			i++;
		}
		else
			total_length += ft_printf_print_char(format[i]);
		i++;
	}
	va_end(args);
	return (total_length);
}
