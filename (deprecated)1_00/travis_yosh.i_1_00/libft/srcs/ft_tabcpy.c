/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 03:49:34 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/24 20:33:11 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_tabcpy(char **in, char **out)
{
	int		i;

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
