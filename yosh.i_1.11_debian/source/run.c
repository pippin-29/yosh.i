/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:38:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/04 14:49:10 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	run(t_cmd *cmd, t_norm *norm)
{
	cmd->rl_yn = 0;
	sig_read_handle(cmd);
	if (cmd->flag == SIMPLECMD)
		run_simplecmd(cmd);
	if (cmd->flag == COMPLEXCMD)
		run_complexcmd(cmd, norm);
}

void	run_simplecmd(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		fprintf(stdout, "Could not create child process.");
	else if (pid == 0)
	{
		if (execve(get_prog_path(cmd->tokens[0], cmd), cmd->tokens,
				cmd->environ) == -1)
		{
			perror(ft_strjoin("yosh.i: command not found: ",
					cmd->tokens[0]));
			exit(errno);
		}
	}
	waitpid(pid, &cmd->estatus, WCONTINUED);
	if (WIFEXITED(cmd->estatus))
		printf("\nChild process exited normally.\n");
}

void	run_complexcmd(t_cmd *cmd, t_norm *norm)
{
	int	i;
	int	command;

	i = 0;
	command = 0;
	cmd->pump = 1;
	redirection(cmd, i, norm);
	while (cmd->tokens[i])
	{
		if (check_4_command(cmd->tokens[i], cmd))
		{
			cmd->cmd = cmd_group(&cmd->tokens[i], find_op(&cmd->tokens[i]));
			command = 1;
		}
		if (ft_strcmp(cmd->tokens[i], PIPE) == 0)
			redirection(cmd, i, norm);
		if (command && (cmd->tokens[i + 1] == NULL
				|| ft_strcmp(cmd->tokens[i + 1], PIPE) == 0))
			runr(cmd);
		i++;
	}
	reset_io(cmd);
	if (WIFEXITED(cmd->estatus))
		printf("\nChild process exited normally.\n");
	cmd->io_cross_in = 0;
}

void	runr(t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("fork error:");
	else if (pid == 0)
	{
		cmd->pump = 0;
		if (execve(get_prog_path(cmd->cmd[0], cmd),
				cmd->cmd, cmd->environ) == -1)
		{
			perror(ft_strjoin("yosh.i: command not found: ", cmd->cmd[0]));
			exit(errno);
		}
	}
	waitpid(pid, &cmd->estatus, WCONTINUED);
}
