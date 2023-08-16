/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 06:57:27 by dhadding          #+#    #+#             */
/*   Updated: 2023/04/19 11:48:38 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	size_total;
	void	*destination;

	size_total = size * count;
	destination = malloc(size_total);
	if (!(destination))
		return (0);
	ft_memset(destination, 0, size_total);
	return (destination);
}
