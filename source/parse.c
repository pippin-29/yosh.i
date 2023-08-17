/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:44:20 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/17 10:06:15 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	parse_input(char *input, t_cmd *cmd)
{
	char **tokens;
	tokens = ft_split(input, ' ');

	cmd->pipredir = find_piperedir(tokens);
	if (cmd->pipredir[0] = '\0')
	{
		if (check_4_builtin(tokens))
			return (0);
		else
			return (1);
	}
	else
	{
		// cmd->cmds = tokenise_tokens(tokens, cmd);
		return (2);
	}
}

// char ***tokenise_tokens(char **tokens, t_cmd *cmd)
// {

// }

char *find_piperedir(char **tokens)
{
	int i;
	int j;
	char *piperedir;

	piperedir = malloc(sizeof(char) * 32);
	i = 0;
	j = 0;
	while (tokens[i])
	{
		if (tokens[i][0] == '|' && tokens[i][1] == '\0')
			piperedir[j++] = '|';
		else if (tokens[i][0] == '<' && tokens[i][1] == '\0')
			piperedir[j++] = '<';
		else if (tokens[i][0] == '>' && tokens[i][1] == '\0')
			piperedir[j++] = '>';
		else if (tokens[i][0] == '>' && tokens[i][1] == '>' && tokens[i][2] == '\0')
			piperedir[j++] = '.';
		else if (tokens[i][0] == '<' && tokens[i][1] == '<' && tokens[i][2] == '\0')
			piperedir[j++] = ',';
		i++;
	}
	piperedir[j] = '\0';
	return (piperedir);
}