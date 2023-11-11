/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:44:20 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/10 09:42:04 by dhadding         ###   ########.fr       */
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
	return (COMPLEXCMD);
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
	print_list_2d(pipredir);
	return (pipredir);
}
