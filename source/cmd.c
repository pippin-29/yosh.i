/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:38:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/17 11:45:51 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void run(int flag, t_cmd *cmd)
{
	if (flag == SIMPLECMD)
		run_simplecmd(cmd);
	// if (flag == COMPLEXCMD)
	// 	run_complex_cmd(cmd);
}

void run_simplecmd(t_cmd *cmd)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		ft_printf("Failed Forking Child;\n");
	else if (pid == 0)
	{
		if(execvp(cmd->cmds[0][0], cmd->cmds[0]) < 0)
			ft_printf("Failed Executing Command;\n");
		exit(0);
	}
	wait(NULL);
	return ;
}

// void run_complexcmd(t_cmd *cmd)
// {
	
// }