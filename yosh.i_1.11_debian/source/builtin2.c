/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:18:35 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/04 11:35:38 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	unset(t_cmd *cmd)
{
	if (!cmd->tokens[2])
		if (rm_envv(cmd->tokens[1], cmd) == 0)
			printf("Failed\n");
	return (1);
}

int	env(t_cmd *cmd)
{
	print_list_2d(cmd->environ);
	return (1);
}

void	cd_empty(t_cmd *cmd)
{
	if (chdir(retrv_envv("HOME", cmd)) == 0)
	{
		add_envv(ft_strjoin("OLDPWD=", retrv_envv("PWD", cmd)), cmd);
		add_envv(ft_strjoin("PWD=", retrv_envv("HOME", cmd)), cmd);
	}
}

int	exports(t_cmd *cmd)
{
	if (!cmd->tokens[2])
		if (add_envv(cmd->tokens[1], cmd) == -1)
			printf("Failed\n");
	return (1);
}
