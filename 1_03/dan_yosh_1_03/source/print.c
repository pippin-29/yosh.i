/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:50:20 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/09 14:24:32 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	print_list_2d(char **list)
{
	int	i;

	i = 0;
	while (list[i])
	{
		printf("String %d - %s", i, list[i]);
		i++;
	}
}

void	print_int_list(int *list, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		printf("%d - ", list[i]);
		i++;
	}
	printf("\n");
}
