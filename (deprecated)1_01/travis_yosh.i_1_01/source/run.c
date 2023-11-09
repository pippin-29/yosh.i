/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:38:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/03 07:30:28 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	run(int flag, t_cmd *cmd)
{
	if (flag == SIMPLECMD)
		run_simplecmd(cmd);
	 /*
	 else if (flag == COMPLEXCMD)
	 	run_cmplxfcker(cmd);
	*/
}

void	run_simplecmd(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_printf("Failed Forking Child;\n");
	else if (pid == 0)
	{
		execve(get_prog_path(cmd->tokens[0]), cmd->tokens, environ);
		perror("execve");
		exit(1);
	}
	free_2d(cmd->tokens);
	wait(NULL);
	return ;
}
/*
void	cmplxfcker(t_cmd *cmd)
{
	int	i;
	int j;
	char *act;

	act = NULL;
	j = 0;
	while (cmd->pipredir[j])
	{
		i = -1;
		while (cmd->pipredir[j][++i] != '\0')
			act[i] = cmd->pipredir[j][i];
		action(act, j, cmd);
		j++;
	}
}
*/