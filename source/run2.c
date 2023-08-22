/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 07:59:53 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/22 11:22:35 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"
extern char **environ;

void	run_pipe(t_cmd *cmd, int a, int trigger)
{
	pid_t pid;
	pipe(cmd->end);
	
	if (!trigger)
	{
		dup2(cmd->end[1], STDOUT_FILENO);
		close(cmd->end[0]);
		pid = fork();
		if (pid == 0)
		{
			execve(get_prog_path(cmd->cmds[a][0]), cmd->cmds[a], environ);
			perror("execve");
			exit(1);
		}
		else if (pid > 0)
		{
			run_complexcmd(cmd, a, 1);
			
		}
	}
	else
	{
		dup2(cmd->end[0], STDIN_FILENO);
		close(cmd->end[1]);
		pid = fork();
		if (pid == 0)
		{
			execve(get_prog_path(cmd->cmds[a + 1][0]), cmd->cmds[a + 1], environ);
			perror("execve");
			exit(1);
		}
		else if (pid > 0)
		{
			run_complexcmd(cmd, a + 1, 0);
			
		}
	}
}

// void	run_redir_from_file(t_cmd *cmd, int a, int trigger)
// {
// 	int	fd_in;
// 	if (!cmd->cmds[a][1])
// 	{
// 		fd_in = open(cmd->cmds[a][0], O_RDONLY);
// 		if (fd_in == -1)
// 		{
// 			ft_printf("Error opening %s\n", cmd->cmds[a][0]);
// 			exit (1);
// 		}
// 	}
// 	else
// 		exit(1);
// 	dup2(fd_in, STDIN_FILENO);
// 	run_complexcmd(cmd, a++);
// }

// void	run_redir_to_file(t_cmd *cmd, int a, int trigger)
// {
// 	int	fd_out;
// 	if (!cmd->cmds[a + 1][1])
// 	{
// 		fd_out = open(cmd->cmds[a + 1][0], O_CREAT | O_WRONLY, 0644);
// 		if (fd_out == -1)
// 		{
// 			ft_printf("Error opening %s\n", cmd->cmds[a + 1][0]);
// 			exit (1);
// 		}
// 	}
// 	else
// 		exit(1);
// 	dup2(fd_out, STDOUT_FILENO);
// 	run_complexcmd(cmd, a++);
// }

// void	run_redir_to_file_append(t_cmd *cmd, int a)
// {

// }

// void	run_redir_from_file_find(t_cmd *cmd, int a)
// {
	
// }