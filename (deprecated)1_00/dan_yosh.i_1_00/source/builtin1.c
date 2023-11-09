/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 05:17:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/13 14:01:14 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	check_4_builtin(char **tokens)
{
	if (strcmp(tokens[0], "exit") == 0)
		exit(0);
	else if (strcmp(tokens[0], "cd") == 0)
		return (cd(tokens));
	else if (strcmp(tokens[0], "pwd") == 0)
		return (pwd());
	else if (strcmp(tokens[0], "export") == 0)
		return (exports(tokens));
	else if (strcmp(tokens[0], "unset") == 0)
		return (unset(tokens));
	else if (strcmp(tokens[0], "env") == 0)
		return (env());
	else if (strcmp(tokens[0], "echo") == 0)
		return (echo(tokens));
	return (0);
}
 
int	echo(char **tokens)
{
	int	i;
	int flag;

	i = 1;
	flag = 0;
	if (strcmp(tokens[1], "-n") == 0)
	{
		i = 2;
		flag = 1;
	}
	while (tokens[i])
	{
		ft_printf("%s", tokens[i]);
		if (tokens[i + 1])
			ft_printf(" ");
		i++;
	}
	if (!flag)
		printf("\n");
	return (1);
}

int	cd(char **tokens)
{
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	if (!tokens[1])
		return (1);
	if (!tokens[2])
	{
		putenv(ft_strjoin("OLDPWD=", cwd));
		chdir(tokens[1]);
		getcwd(cwd, sizeof(cwd));
		putenv(ft_strjoin("PWD=", cwd));
	}
	return (1);
}

int	pwd(void)
{
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	ft_printf("%s\n", cwd);
	return (1);
}

int	exports(char **tokens)
{
	if (!tokens[2])
		if (putenv(tokens[1]) == -1)
			ft_printf("Failed\n");
	return (1);
}
