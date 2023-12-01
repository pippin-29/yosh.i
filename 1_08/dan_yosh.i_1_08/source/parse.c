/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:44:20 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/01 13:20:43 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"


int	parse_input(t_cmd *cmd, t_norm *norm)
{
	char	*s;
	char	*tmp;

	tmp = NULL;
	s = dequote_built(cmd->expanded, tmp, norm);
	cmd->tokens = ft_split(s, ' ');
	find_pipes_redirection(cmd);
	if (cmd->pipredir[0] == NULL)
	{
		if (run_builtin(cmd->tokens))
			return (BUILTINCMD);
		else
			return (SIMPLECMD);
	}
	return (COMPLEXCMD);
}

int	reject_char(t_cmd *cmd, int tar)
{
	char	*s;
	int		i;
	int		f;
	int		c;

	s = cmd->expanded;
	i = 0;
	f = 0;
	c = 0;
	while (s[i] && c != tar)
	{
		if (s[i] == ' ')
		{
			while (s[i] == ' ')
				i++;
			if (s[i])
				c++;
		}
		i++;
	}
	f += doub_c(s, i);
	f += sing_c(s, i);
	return (f);
}

void	find_pipes_redirection(t_cmd *cmd)
{
	int		i;
	int		j;
	int		f;

	cmd->pipredir = malloc(sizeof(char *) * 32);
	i = 0;
	j = 0;
	while (cmd->tokens[i])
	{
		f = 0;
		f += reject_char(cmd, i);
		if (ft_strcmp(cmd->tokens[i], PIPE) == 0 && f == 0)
			cmd->pipredir[j++] = strdup("|");
		else if (ft_strcmp(cmd->tokens[i], IN) == 0 && f == 0)
			cmd->pipredir[j++] = strdup("<");
		else if (ft_strcmp(cmd->tokens[i], OUT) == 0 && f == 0)
			cmd->pipredir[j++] = strdup(">");
		else if (ft_strcmp(cmd->tokens[i], APPEND) == 0 && f == 0)
			cmd->pipredir[j++] = strdup(">>");
		else if (ft_strcmp(cmd->tokens[i], HERE) == 0 && f == 0)
			cmd->pipredir[j++] = strdup("<<");
		i++;
	}
	cmd->pipredir[j] = NULL;
}

char	**cmd_group(char **token_group, int end)
{
	char	**cmd_group;
	int		i;

	i = 0;
	cmd_group = malloc(sizeof(char *) * (16));
	while (i < end)
	{
		if (token_group[i][0] != '|')
			cmd_group[i] = strdup(token_group[i]);
		else
			break ;
		i++;
	}
	cmd_group[i] = NULL;
	return (cmd_group);
}
