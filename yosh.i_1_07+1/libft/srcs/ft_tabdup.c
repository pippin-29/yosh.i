/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:49:34 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/30 09:17:10 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_tabdup(char **in)
{
	int		i;
	char	**out;

	i = 0;
	out = malloc (sizeof(char *) * (ft_lstlen(in) + 1));
	if (!out)
		return (NULL);
	while (in[i])
	{
		out[i] = ft_strdup(in[i]);
		i++;
	}
	out[i] = NULL;
	return (out);
}
