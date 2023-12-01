/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe-io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:41:07 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/01 13:19:49 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	out_command(t_cmd *cmd)
{
	cmd->fd_stdout = dup(STDOUT_FILENO);
	cmd->fd_to_pipe = open(ft_strjoin(retrv_envv("HOME"), "/.to-pipe"), O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (cmd->fd_to_pipe == -1)
		perror("Error: to_pipe !open");
	dup2(cmd->fd_to_pipe, STDOUT_FILENO);
	cmd->pump = 0;
	return (1);
}

int	in_command(t_cmd *cmd)
{
	reset_io(cmd);
	cmd->fd_stdin = dup(STDIN_FILENO);
	cmd->fd_from_pipe = open(ft_strjoin(retrv_envv("HOME"), "/.to-pipe"), O_RDONLY);
	if (cmd->fd_from_pipe == -1)
		perror("Error: from_pipe !open");
	dup2(cmd->fd_from_pipe, STDIN_FILENO);
	cmd->pump = 1;
	return (1);
}
