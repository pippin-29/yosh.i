/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:44:20 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/22 12:51:36 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	parse_input(t_cmd *cmd)
{
	cmd->tokens = ft_split(cmd->expanded, ' ');
	find_pipes_redirection(cmd);
	if (cmd->pipredir[0] == NULL)
	{
		if (check_4_builtin(cmd->tokens))
			return (BUILTINCMD);
		else
			return (SIMPLECMD);
	}
	return (COMPLEXCMD);
}

void	find_pipes_redirection(t_cmd *cmd)
{
	int		i;
	int		j;

	cmd->pipredir = malloc(sizeof(char *) * 32);
	i = 0;
	j = 0;
	while (cmd->tokens[i])
	{
		if (ft_strcmp(cmd->tokens[i], PIPE) == 0)
			cmd->pipredir[j++] = strdup("|");
		else if (ft_strcmp(cmd->tokens[i], IN) == 0)
			cmd->pipredir[j++] = strdup("<");
		else if (ft_strcmp(cmd->tokens[i], OUT) == 0)
			cmd->pipredir[j++] = strdup(">");
		else if (ft_strcmp(cmd->tokens[i], APPEND) == 0)
			cmd->pipredir[j++] = strdup(">>");
		else if (ft_strcmp(cmd->tokens[i], HERE) == 0)
			cmd->pipredir[j++] = strdup("<<");
		i++;
	}
	cmd->pipredir[j] = NULL;
}

char **cmd_group(char **token_group, int end)
{
	char **cmd_group;
	int	i;

	i = 0;
	cmd_group = malloc(sizeof(char *) * (16));
	while (i < end)
	{
		cmd_group[i] = strdup(token_group[i]);
		i++;
	}
	cmd_group[i] = NULL;
	return (cmd_group);
}
