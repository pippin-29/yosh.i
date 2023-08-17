/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 05:17:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/18 09:13:15 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int check_4_builtin(char **tokens)
{
	if (strcmp(tokens[0], "exit") == 0)
		exit(0);
	else if (strcmp(tokens[0], "cd") == 0)
		return (cd(tokens));
	else if (strcmp(tokens[0], "pwd") == 0)
		return (pwd());
	else if (strcmp(tokens[0], "export") == 0)
		return (export(tokens));
	else if (strcmp(tokens[0], "unset") == 0)
		return (unset(tokens));
	else if (strcmp(tokens[0], "env") == 0)
		return (env());
	else if (strcmp(tokens[0], "echo") == 0)
		return (echo(tokens));
	return (0);
}

int echo(char **tokens)
{
	int i;

	i = 1;
	if (strcmp(tokens[1], "-n") == 0)
		i = 2;
	while(tokens[i])
	{
		ft_printf("%s", tokens[i]);
		if (tokens[i + 1])
			ft_printf(" ");
		i++;
	}
	ft_printf("\n");
	return (1);
}

int cd(char **tokens)
{
	if (!tokens[2])
		chdir(tokens[1]);
	return (1);
}

int pwd(void)
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	ft_printf("%s\n", cwd);
	return (1);
}

int export(char **tokens)
{
	if (!tokens[2])
		if (putenv(tokens[1]) == -1)
			ft_printf("Failed");
	return (1);
}
