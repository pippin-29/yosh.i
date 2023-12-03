/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:01:41 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/03 10:18:33 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*malloc_strlen_n(unsigned int c, va_list arg)
{
	unsigned int	size;
	va_list			arg_copy;

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
	t_sje	*st;

	st = malloc(sizeof(t_sje));
	va_start(st->arg, c);
	st->out = malloc_strlen_n(c, st->arg);
	st->j = 0;
	if (!st->out)
	{
		va_end(st->arg);
		return (0);
	}
	while (c)
	{
		st->i = 0;
		st->tmp = va_arg(st->arg, char *);
		while (st->tmp[st->i])
			st->out[st->j++] = st->tmp[st->i++];
		c--;
	}
	st->out[st->j] = '\0';
	va_end(st->arg);
	return (st->out);
}
