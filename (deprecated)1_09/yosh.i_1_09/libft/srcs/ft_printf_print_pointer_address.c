/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_pointer_address.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:36:53 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/09 15:22:35 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_printf_print_char(num + '0');
		else
			ft_printf_print_char(num - 10 + 'a');
	}
}

int	ft_printf_print_pointer(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}
