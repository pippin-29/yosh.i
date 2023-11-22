/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 05:57:50 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/10 16:33:48 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*out;
	size_t	i;

	out = malloc(n + 1);
	if (!out)
		return (0);
	i = 0;
	while (i < n && s[i])
	{
		out[i] = s[i];
		i++;
	}
	while (i <= n)
		out[i++] = 0;
	return (out);
}
