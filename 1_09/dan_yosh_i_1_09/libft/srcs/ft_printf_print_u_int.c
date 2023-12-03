/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_u_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 09:37:09 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/10 17:00:16 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_unsigned_num_len(unsigned int num)
{
	size_t	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_unsigned_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (num);
}

int	ft_printf_print_u_int(unsigned int u)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (u == 0)
		print_length += write(1, "0", 1);
	else
	{
		num = ft_uitoa(u);
		print_length += ft_printf_print_str(num);
		free(num);
	}
	return (print_length);
}
