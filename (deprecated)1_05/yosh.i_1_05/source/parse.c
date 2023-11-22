/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:44:20 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/10 15:41:45 by dhadding         ###   ########.fr       */
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
		if (strcmp(cmd->tokens[i], "|\0") == 0)
			cmd->pipredir[j++] = strdup("|");
		else if (strcmp(cmd->tokens[i], "<\0") == 0)
			cmd->pipredir[j++] = strdup("<");
		else if (strcmp(cmd->tokens[i], ">\0") == 0)
			cmd->pipredir[j++] = strdup(">");
		else if (strcmp(cmd->tokens[i], ">>\0") == 0)
			cmd->pipredir[j++] = strdup(">>");
		else if (strcmp(cmd->tokens[i], "<<\0") == 0)
			cmd->pipredir[j++] = strdup("<<");
		i++;
	}
	cmd->pipredir[j] = NULL;
}
