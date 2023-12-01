/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:18:35 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/01 14:00:19 by dhadding         ###   ########.fr       */
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
	unlink(ft_strjoin(retrv_envv("HOME"), "/.temporary_heredoc"));
	unlink(ft_strjoin(retrv_envv("HOME"), "/.to-pipe"));
	save_history();
	exit(0);
}

void	cd_empty(void)
{
	if (chdir(retrv_envv("HOME")) == 0)
	{
		add_envv(ft_strjoin("OLDPWD=", retrv_envv("PWD")));
		add_envv(ft_strjoin("PWD=", retrv_envv("HOME")));
	}
}

int	export(char **tokens)
{
	if (!tokens[2])
		if (add_envv(tokens[1]) == -1)
			printf("Failed\n");
	return (1);
}