/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:38:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/09 15:24:55 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	run(int flag, t_cmd *cmd)
{
	if (flag == SIMPLECMD)
		run_simplecmd(cmd);
	// else if (flag == COMPLEXCMD)
	// 	run_complexcmd(cmd, 0, 0);
}

// void	run_complexcmd(t_cmd *cmd, int a, int trigger)
// {
// 	if (cmd->pipredir[a] == '|')
// 		run_pipe(cmd, a, trigger);
// 	// else if (cmd->pipredir[a] == '<' && trigger == 0)
// 	// 	run_redir_from_file(cmd, a, trigger);
// 	// else if (cmd->pipredir[a] == '>' && trigger == 1)
// 	// 	run_redir_to_file(cmd, a, trigger);
// 	// else if (cmd->pipredir[a] == '.')
// 	// 	run_redir_to_file_append(cmd, a);
// 	// else if (cmd->pipredir[a] == ',')
// 	// 	run_redir_from_file_find(cmd, a);
// }

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
 