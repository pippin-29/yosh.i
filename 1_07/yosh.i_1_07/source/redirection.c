/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:20:13 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/28 10:33:16 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	redirection(t_cmd *cmd, int i)
{
	int	q;
	int	ret;

	q = i;
	ret = 0;
	while (cmd->tokens[q] != NULL)
	{
		if (ft_strcmp(cmd->tokens[q], PIPE) == 0)
			return (ret);
		if (ft_strcmp(cmd->tokens[q], IN) == 0)
			ret += in(cmd, q);
		else if (ft_strcmp(cmd->tokens[q], HERE) == 0)
			ret += in_here(cmd, q);
		if (ft_strcmp(cmd->tokens[q], OUT) == 0)
			ret += out(cmd, q);
		else if (ft_strcmp(cmd->tokens[q], APPEND) == 0)
			ret += out_append(cmd, q);
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
