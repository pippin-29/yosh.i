/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:38:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/18 09:51:33 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	run(int flag, t_cmd *cmd)
{
	if (flag == SIMPLECMD)
		run_simplecmd(cmd);
}

void	run_simplecmd(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_printf("Failed Forking Child;\n");
	else if (pid == 0)
	{
		if (execvp(cmd->tokens[0], cmd->tokens) < 0)
			ft_printf("Failed Executing Command;\n");
		exit(0);
	}
	free_2d(cmd->tokens);
	wait(NULL);
	return ;
}
