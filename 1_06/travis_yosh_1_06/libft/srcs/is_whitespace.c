/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:02:24 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/10 16:31:57 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

bool	is_whitespace(char *s)
{
	int	i;
	int	len;

	len = ft_strlen(s);
	i = 0;
	while (s[i])
	{
		if (i != len)
		{
			if (s[i] != ' ')
				return (false);
			i++;
		}
	}
	return (true);
}
