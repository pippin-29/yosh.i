/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:38:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/10 08:49:11 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

extern int	g_estatus;

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
		fprintf(stdout, "Could not create child process.");
	else if (pid == 0)
	{
		if (execve(get_prog_path(cmd->tokens[0]), cmd->tokens, environ) == -1)
		{
			perror(ft_strjoin("yosh.i: command not found: ", cmd->tokens[0]));
			exit(errno);
		}
	}
	waitpid(pid, &g_estatus, WCONTINUED);
	if (WIFEXITED(g_estatus))
		printf("\nChild process exited normally.\n");
	free_2d_char(cmd->tokens);
}
