/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:20:13 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/04 14:27:47 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	pipe_next(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (ft_strcmp(tokens[i], PIPE) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	redirection(t_cmd *cmd, int i, t_norm *norm)
{
	int	q;
	int	ret;

	q = i;
	ret = 0;
	cmd->io_dup_in = 0;
	cmd->io_dup_out = 0;
	cmd->io_cross_in = 0;
	while (cmd->tokens[q] != NULL)
	{
		if (cmd->pump == 0)
			ret += in_command(cmd);
		if (ft_strcmp(cmd->tokens[q], IN) == 0)
			ret += in(cmd, q);
		else if (ft_strcmp(cmd->tokens[q], HERE) == 0)
			ret += in_here(cmd, q, norm);
		if (ft_strcmp(cmd->tokens[q], OUT) == 0)
			ret += out(cmd, q);
		else if (ft_strcmp(cmd->tokens[q], APPEND) == 0)
			ret += out_append(cmd, q);
		if (cmd->pump == 1 && pipe_next(&cmd->tokens[q + 1]))
			return (ret += out_command(cmd));
		q++;
	}
	return (ret);
}

int	count_pipes(t_cmd *cmd)
{
	int	i;

	i = 0;
	cmd->pipe_c = 0;
	while (cmd->pipredir[i])
	{
		if (ft_strcmp(cmd->pipredir[i], PIPE) == 0)
			cmd->pipe_c++;
		i++;
	}
	return (cmd->pipe_c);
}

void	reset_io(t_cmd *cmd)
{
	dup2(cmd->fd_stdin, STDIN_FILENO);
	dup2(cmd->fd_stdout, STDOUT_FILENO);
}
