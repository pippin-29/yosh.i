/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 05:17:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/30 10:43:34 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	check_4_builtin(char **tokens)
{
	if (ft_strcmp(tokens[0], "exit") == 0)
		exitshell();
	else if (ft_strcmp(tokens[0], "cd") == 0)
		return (cd(tokens));
	else if (ft_strcmp(tokens[0], "pwd") == 0)
		return (pwd());
	else if (ft_strcmp(tokens[0], "export") == 0)
		return (exports(tokens));
	else if (ft_strcmp(tokens[0], "unset") == 0)
		return (unset(tokens));
	else if (ft_strcmp(tokens[0], "env") == 0)
		return (env());
	else if (ft_strcmp(tokens[0], "echo") == 0)
		return (echo(tokens));
	else if (ft_strcmp(tokens[0], "continue") == 0)
		return (continue_w_error(tokens));
	return (0);
}

int	echo(char **tokens)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (!tokens[1])
		return (1);
	if (ft_strcmp(tokens[1], "-n") == 0)
	{
		i = 2;
		flag = 1;
	}
	while (tokens[i])
	{
		printf("%s", tokens[i]);
		if (tokens[i + 1])
			printf(" ");
		i++;
	}
	if (!flag)
		printf("\n");
	return (1);
}

int	cd(char **tokens)
{
	char	*cwd;

	cwd = retrv_envv("PWD");
	if (!tokens[1])
	{
		add_envv(ft_strjoin("OLDPWD=", cwd));
		add_envv(ft_strjoin("PWD=", retrvv_cwd(retrv_envv("HOME"), cwd)));
		chdir("$HOME");
	}
	if (!tokens[2])
	{
		add_envv(ft_strjoin("OLDPWD=", cwd));
		add_envv(ft_strjoin("PWD=", retrvv_cwd(tokens[1], cwd)));
		chdir(tokens[1]);
	}
	return (1);
}

int	pwd(void)
{
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
	return (1);
}

int	exports(char **tokens)
{
	if (!tokens[2])
		if (add_envv(tokens[1]) == -1)
			printf("Failed\n");
	return (1);
}
