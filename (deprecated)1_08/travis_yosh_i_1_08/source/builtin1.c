/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 05:17:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/01 09:23:03 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	check_4_builtin(char **tokens)
{
	if (ft_strcmp(tokens[0], "exit") == 0)
		exitshell();
	else if (ft_strcmp(tokens[0], "cd") == 0)
		return (1);
	else if (ft_strcmp(tokens[0], "pwd") == 0)
		return (1);
	else if (ft_strcmp(tokens[0], "export") == 0)
		return (1);
	else if (ft_strcmp(tokens[0], "unset") == 0)
		return (1);
	else if (ft_strcmp(tokens[0], "env") == 0)
		return (1);
	else if (ft_strcmp(tokens[0], "echo") == 0)
		return (1);
	return (0);
}

int run_builtin(char **tokens)
{
	if (ft_strcmp(tokens[0], "cd") == 0)
		return (cd(tokens));
	else if (ft_strcmp(tokens[0], "pwd") == 0)
		return (pwd());
	else if (ft_strcmp(tokens[0], "export") == 0)
		return (export(tokens));
	else if (ft_strcmp(tokens[0], "unset") == 0)
		return (unset(tokens));
	else if (ft_strcmp(tokens[0], "env") == 0)
		return (env());
	else if (ft_strcmp(tokens[0], "echo") == 0)
		return (echo(tokens));
	return (BUILTINCMD);
}

int	echo(char **tokens)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (!tokens[1] || echo_is_on_path())
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
	char	cwd[INLEN];

	getcwd(cwd, sizeof(cwd));
	if (!tokens[1])
	{
		cd_empty();
	}
	else if (!tokens[2])
	{
		if (chdir(tokens[1]) == 0)
		{
			getcwd(cwd, sizeof(cwd));
			add_envv(ft_strjoin("OLDPWD=", retrv_envv("PWD")));
			add_envv(ft_strjoin("PWD=", cwd));
		}
	}
	return (1);
}

int	pwd(void)
{
	char	cwd[INLEN];

	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
	return (1);
}
