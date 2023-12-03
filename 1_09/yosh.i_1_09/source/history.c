/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:38:27 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/01 11:52:41 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	load_history(void)
{
	if (read_history(ft_strjoin(retrv_envv("HOME"), "/.yosh_history")) != 0)
	{
		printf("Unable to load history file\n");
	}
}

void	save_history(void)
{
	if (write_history(ft_strjoin(retrv_envv("HOME"), "/.yosh_history")) != 0)
	{
		printf("Unable to save history file\n");
	}
}
