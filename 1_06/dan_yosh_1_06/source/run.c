/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:38:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/22 13:21:03 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	run(t_cmd *cmd)
{
	if (cmd->flag == SIMPLECMD)
		run_simplecmd(cmd);
	if (cmd->flag == COMPLEXCMD)
		run_complexcmd(cmd);
}

void	runf(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("fork error:");
	else if (pid == 0)
	{
		if (execve(get_prog_path(cmd->cmd[0]), cmd->cmd, environ) == -1)
		{
			perror(ft_strjoin("yosh.i: command not found: ", cmd->cmd[0]));
			exit(errno);
		}
	}
	waitpid(pid, &cmd->estatus, WCONTINUED);
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
	waitpid(pid, &cmd->estatus, WCONTINUED);
	if (WIFEXITED(cmd->estatus))
		printf("\nChild process exited normally.\n");
}

void	run_complexcmd(t_cmd *cmd)
{
	int		i;
	
	i = 0;
	while (cmd->tokens[i])
	{
		if (check_4_command(cmd->tokens[i]))
			cmd->cmd = cmd_group(&cmd->tokens[i], find_op(&cmd->tokens[i]));
		if (redirection(cmd, i) || piper(cmd, i) || last_command(cmd, i))
			if (check_4_command(cmd->tokens[i]))
				runf(cmd);
		if (last_command(cmd, i))
		{
			reset_io(cmd);
			break ;
		}	
		i++;
	}
	if (WIFEXITED(cmd->estatus))
		printf("\nChild process exited normally.\n");
}
