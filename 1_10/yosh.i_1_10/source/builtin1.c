/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 05:17:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/03 13:02:37 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	run_builtin(t_cmd *cmd)
{
	if (ft_strcmp(cmd->tokens[0], "exit") == 0)
		exitshell(cmd);
	else if (ft_strcmp(cmd->tokens[0], "cd") == 0)
		return (cd(cmd));
	else if (ft_strcmp(cmd->tokens[0], "pwd") == 0)
		return (pwd());
	else if (ft_strcmp(cmd->tokens[0], "export") == 0)
		return (exports(cmd));
	else if (ft_strcmp(cmd->tokens[0], "unset") == 0)
		return (unset(cmd));
	else if (ft_strcmp(cmd->tokens[0], "env") == 0)
		return (env(cmd));
	else if (ft_strcmp(cmd->tokens[0], "echo") == 0)
		return (echo(cmd));
	return (BUILTINCMD);
}

int	echo(t_cmd *cmd)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (!cmd->tokens[1])
		return (printf("\n"));
	if (ft_strcmp(cmd->tokens[1], "-n") == 0)
	{
		i = 2;
		flag = 1;
	}
	while (cmd->tokens[i])
	{
		printf("%s", cmd->tokens[i]);
		if (cmd->tokens[i + 1])
			printf(" ");
		i++;
	}
	if (!flag)
		printf("\n");
	return (1);
}

int	cd(t_cmd *cmd)
{
	char	cwd[INLEN];

	getcwd(cwd, sizeof(cwd));
	if (!cmd->tokens[1])
		cd_empty(cmd);
	else if (!cmd->tokens[2])
	{
		if (chdir(cmd->tokens[1]) == 0)
		{
			getcwd(cwd, sizeof(cwd));
			add_envv(ft_strjoin("OLDPWD=", retrv_envv("PWD", cmd)), cmd);
			add_envv(ft_strjoin("PWD=", cwd), cmd);
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
