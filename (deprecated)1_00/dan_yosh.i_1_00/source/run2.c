/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 07:59:53 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/09 15:24:57 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"
extern char **environ;

// void	run_pipe(t_cmd *cmd, int a, int trigger)
// {
	
// }

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