/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:18:35 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/30 14:27:40 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

extern char	**g_environ2;

int	unset(char **tokens)
{
	if (!tokens[2])
		if (rm_envv(tokens[1]) == 0)
			printf("Failed\n");
	return (1);
}

int	env(void)
{
	print_list_2d(g_environ2);
	return (1);
}

void	exitshell(void)
{
	unlink(".temporary_heredoc");
	unlink(".to-pipe");
	save_history();
	exit(0);
}

int	continue_w_error(char **tokens)
{
	if (tokens[1] && ft_strcmp(tokens[1], "unclosed") == 0)
	{
		printf("Quotes must be closed\n");
		return (1);
	}
	else
		return (1);
}
