/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:40:18 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/04 14:50:29 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	find_op(char **tokens)
{
	int	i;

	i = 1;
	while (tokens[i])
	{
		if (ft_strcmp(tokens[i], IN) == 0)
			return (i);
		if (ft_strcmp(tokens[i], OUT) == 0)
			return (i);
		if (ft_strcmp(tokens[i], APPEND) == 0)
			return (i);
		if (ft_strcmp(tokens[i], HERE) == 0)
			return (i);
		i++;
	}
	return (i);
}

int	check_4_command(char *cmd_alpha, t_cmd *cmd)
{
	if (is_prog_on_path(cmd_alpha, cmd))
		return (1);
	else
		return (0);
}

int	is_prog_on_path(char *prog_name, t_cmd *cmd)
{
	char	**paths;
	int		i;

	i = 0;
	paths = ft_split(retrv_envv("PATH", cmd), ':');
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		paths[i] = ft_strjoin(paths[i], prog_name);
		if (access(paths[i], F_OK) == 0)
		{
			free_2d_char(paths);
			return (1);
		}
		i++;
	}
	free_2d_char(paths);
	return (0);
}

int	last_command(t_cmd *cmd, int i)
{
	int	q;

	q = i;
	while (cmd->tokens[q])
	{
		if (ft_strcmp(cmd->tokens[q], PIPE) == 0)
			return (0);
		q++;
	}
	return (1);
}
