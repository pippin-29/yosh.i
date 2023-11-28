/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:20:13 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/22 13:17:47 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	redirection(t_cmd *cmd, int i)
{
	int q;
	int ret;

	q = i;
	ret = 0;
	while(cmd->tokens[q])
	{
		if (ft_strcmp(cmd->tokens[q], IN) == 0)
			ret += in(cmd, q);
		else if (ft_strcmp(cmd->tokens[q], HERE) == 0)
			ret += in_here(cmd, q);
		if (ft_strcmp(cmd->tokens[q], OUT) == 0)
			ret += out(cmd, q);
		else if (ft_strcmp(cmd->tokens[q], APPEND) == 0)
			ret += out_append(cmd, q);
		if (ft_strcmp(cmd->tokens[q], PIPE) == 0)
			return (ret);
		q++;
	}
	return (ret);
}

int	piper(t_cmd *cmd, int i)
{
	int q;

	q = i;
	while (cmd->tokens[q])
	{
		if (ft_strcmp(cmd->tokens[q], PIPE))
			return (pepper(cmd));
		i++;
	}
	return (0);
}

int pepper(t_cmd *cmd)
{
	(void)cmd;
	return (1);
}

void	reset_io(t_cmd *cmd)
{
	dup2(cmd->fd_stdin, STDIN_FILENO);
	dup2(cmd->fd_stdout, STDOUT_FILENO);
}
