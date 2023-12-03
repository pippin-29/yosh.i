/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:38:27 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/03 13:36:43 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	load_history(t_cmd *cmd)
{
	if (read_history(ft_strjoin(retrv_envv("HOME", cmd),
				"/.yosh_history")) != 0)
	{
		printf("Unable to load history file\n");
	}
}

void	save_history(t_cmd *cmd)
{
	if (write_history(ft_strjoin(retrv_envv("HOME", cmd),
				"/.yosh_history")) != 0)
	{
		printf("Unable to save history file\n");
	}
}
