/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:44:20 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/13 13:27:17 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	parse_input(char *input, t_cmd *cmd)
{
	cmd->tokens = ft_split(input, ' ');
	cmd->pipredir = find_pipredir(cmd->tokens);
	if (cmd->pipredir[0] == NULL)
	{
		if (check_4_builtin(cmd->tokens))
			return (BUILTINCMD);
		else
			return (SIMPLECMD);
	}
	else
	{
		cmd->cmds = cmd_list(cmd->tokens, cmd->pipredir);
		return (COMPLEXCMD);
	}
}

char	***cmd_list(char **tokens, char **pipredir)
{
	char	***cmds;
	int		i;
	int		a;
	int		b;
	int		f;

	i = 0;
	a = 0;
	b = 0;
	f = 0;
	cmds = (char ***)malloc(sizeof(char **) * (32));
	while (tokens[i])
	{
		if (pipredir[f])
		{
			if ((strcmp(tokens[i], pipredir[f]) == 0))
			{
				cmds[a][b] = NULL;
				a++;
				f++;
				i++;
				b = 0;
			}
		}
		
		cmds[a] = malloc(sizeof(char *) * (16));
		cmds[a][b] = ft_strdup(tokens[i]);
		b++;
		i++;
	}
	cmds[a][b] = NULL;
	a++;
	cmds[a] = NULL;
	return (cmds);
}

char	**find_pipredir(char **tokens)
{
	int		i;
	int		j;
	char	**pipredir;

	pipredir = malloc(sizeof(char *) * 32);
	i = 0;
	j = 0;
	while (tokens[i])
	{
		if (strcmp(tokens[i], "|\0") == 0)
			pipredir[j++] = strdup("|");
		else if (strcmp(tokens[i], "<\0") == 0)
			pipredir[j++] = strdup("<");
		else if (strcmp(tokens[i], ">\0") == 0)
			pipredir[j++] = strdup(">");
		else if (strcmp(tokens[i], ">>\0") == 0)
			pipredir[j++] = strdup(">>");
		else if (strcmp(tokens[i], "<<\0") == 0)
			pipredir[j++] = strdup("<<");
		i++;
	}
	pipredir[j] = NULL;
	return (pipredir);
}
