/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:01:41 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/09 14:01:00 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*malloc_strlen_n(unsigned int c, va_list arg)
{
	unsigned int size;
	va_list arg_copy;

	va_copy(arg_copy, arg);
	size = 0; 
	while (c)
	{
		size += ft_strlen(va_arg(arg_copy, char *));
		c--;
	}
	va_end(arg_copy);
	return (malloc(sizeof(char) * (size + 1)));
}

char	*strjoin_e(unsigned int c, ...)
{
	va_list arg;
	char	*out;
	char	*tmp;
	int		i;
	int		j;

	va_start(arg, c);
	out = malloc_strlen_n(c, arg);
	j = 0;
	if (!out)
	{
		va_end(arg);
		return (0);
	}
	while (c)
	{
		i = 0;
		tmp = va_arg(arg, char *);
		while (tmp[i])
		{
			out[j] = tmp[i];
			j++;
			i++;
		}
		c--;
	}
	out[j] = '\0';
	va_end(arg);
	return (out);
}
