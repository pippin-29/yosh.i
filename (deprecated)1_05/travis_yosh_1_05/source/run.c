/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:38:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/22 03:07:12 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	run(t_cmd *cmd)
{
	cmd->rl_yn = 0;
	sig_read_handle(cmd);
	if (cmd->flag == SIMPLECMD)
		run_simplecmd(cmd);
	// if (cmd->flag == COMPLEXCMD)
	// 	run_complexcmd(cmd);
}

void	run_simplecmd(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		fprintf(stdout, "Could not create child process.");
	if (pid == 0)
	{
		if (execve(get_prog_path(cmd->tokens[0]), cmd->tokens, environ) == -1)
		{
			perror(ft_strjoin("yosh.i: command not found: ", cmd->tokens[0]));
			exit(errno);
		}
	}
	waitpid(pid, &cmd->estatus, WCONTINUED);
	if (WIFEXITED(cmd->estatus))
		printf("\nChild process exited normally.\n");
	free_2d_char(cmd->tokens);
}
