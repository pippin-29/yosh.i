/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:38:27 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/10 15:52:17 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	load_history(void)
{
	if (read_history(HISTORY_PATH) != 0)
	{
		printf("Unable to load history file\n");
	}
}

void	save_history(void)
{
	if (write_history(HISTORY_PATH) != 0)
	{
		printf("Unable to save history file\n");
	}
}
