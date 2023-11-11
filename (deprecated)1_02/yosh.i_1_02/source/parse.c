/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:44:20 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/06 12:18:55 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"


// int	parse_input(char *input, t_cmd *cmd)
// {
	

// 	tokeniser(input, cmd);
// 	return (0);
// 	print_list_2d(cmd->tokens);
// 	printf("\n");
// 	return (0);
// 	// designed for replacement of ft_split
// 	// should take into account (""), (''), ($), and interpretation of \, ;,
// 	// and unclosed quotes.

// 	cmd->pipredir = find_pipredir(cmd->tokens);
// 	if (cmd->pipredir[0] == NULL)
// 	{
// 		if (check_4_builtin(cmd->tokens))
// 			return (BUILTINCMD);
// 		else
// 			return (SIMPLECMD);
// 	}
// 	else
// 	{
// 		print_list_2d(cmd->tokens);
// 		cmd->cmds = cmd_list(cmd->tokens, cmd->pipredir);
// 		return (COMPLEXCMD);
// 	}
// }

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
	// else
	// {
	// 	cmd->cmds = cmd_list(cmd->tokens, cmd->pipredir);
	// 	return (COMPLEXCMD);
	// }
}

// void	tokeniser(char *input, t_cmd *cmd)
// {
// 	log_single_quotes(input, cmd);
// 	log_double_quotes(input, cmd);
// 	if ((cmd->sqc % 2) || (cmd->dqc % 2))
// 	{
// 		cmd->tokens = token_pair("continue" ,"unclosed");
// 		return ;
// 	}
// 	split_w_quotes(input, cmd);
// }

// char **token_pair(char *one, char *two)
// {
// 	char **pair;

// 	pair = malloc(sizeof(char *) * 3);
// 	pair[0] = ft_strdup(one);
// 	pair[1] = ft_strdup(two);
// 	pair[2] = (NULL);

// 	return (pair);
// }



// char ***cmd_list(char **tokens, char **pipredir)
// {
// 	char ***cmds;
// 	int tok = 0;
// 	int list = 0;
// 	int cmd = 0;
// 	int del = 0;
	
// 	cmds = (char ***)malloc(sizeof(char **) * (32));
// 	while (tokens[tok])
// 	{
// 		cmds[list] = malloc(sizeof(char *) * (16));
// 		if (strcmp(tokens[tok], pipredir[del]) == 0)
// 		{
// 			cmds[list][cmd] = NULL;
// 			cmd = 0;
// 			list++;
// 			if (pipredir[del + 1])
// 				del++;
// 		}
// 		cmds[list][cmd] = ft_strdup(tokens[tok]);
// 		cmd++;
// 		tok++;
// 	}
// 	cmds[list][cmd] = NULL;
// 	list++;
// 	cmds[list] = NULL;
// 	// print_list_3d(cmds);
// 	return (cmds);
// }

// char	***cmd_list(char **tokens, char **pipredir)
// {
// 	char	***cmds;
// 	int		i;
// 	int		a;
// 	int		b;
// 	int		f;

// 	i = 0;
// 	a = 0;
// 	b = 0;
// 	f = 0;
// 	cmds = (char ***)malloc(sizeof(char **) * (64));
// 	while (tokens[i])
// 	{
// 		cmds[a] = malloc(sizeof(char *) * (64));
// 		if (pipredir[f])
// 		{
// 			if ((strcmp(tokens[i], pipredir[f]) == 0))
// 			{
// 				cmds[a][b] = NULL;
// 				printf("%d\n", a);
// 				a++;
// 				f++;
// 				i++;
// 				b = 0;
// 			}
// 		}
		
// 		cmds[a][b] = ft_strdup(tokens[i]);
// 		b++;
// 		i++;
// 	}
// 	cmds[a][b] = NULL;
// 	a++;
// 	cmds[a] = NULL;
// 	print_list_3d(cmds);
// 	return (cmds);
// }



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
