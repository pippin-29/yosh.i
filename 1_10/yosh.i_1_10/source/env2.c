/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:10:30 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/03 15:27:21 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	rm_envv(char *envvar, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->environ[i])
	{
		if (ft_strncmp(envvar, cmd->environ[i], ft_strlen(envvar)) == 0)
			if (cmd->environ[i][ft_strlen(envvar)] == '=')
				return (contract_env(i, cmd));
		i++;
	}
	return (0);
}

int	contract_env(int index, t_cmd *cmd)
{
	int		i;
	int		q;
	char	**copy;

	i = 0;
	q = 0;
	if (cmd->environ[index + 1] == NULL)
		cmd->environ[index] = NULL;
	copy = malloc(sizeof(char *) * (ft_lstlen(cmd->environ) + 1));
	if (!copy)
		return (0);
	while (cmd->environ[q])
	{
		if (i == index)
			q++;
		copy[i] = ft_strdup(cmd->environ[q]);
		i++;
		q++;
	}
	copy[i] = NULL;
	copy_environ(copy, cmd);
	free(copy);
	return (1);
}

int	add_envv(char *envvar, t_cmd *cmd)
{
	int		i;
	char	**temp;

	i = 0;
	if (error_check_add_envv(envvar))
		return (-1);
	if (update_envv(envvar, cmd))
		return (1);
	temp = ft_tabdup(cmd->environ);
	cmd->environ = malloc(sizeof(char *) * (ft_lstlen(temp) + 2));
	while (temp[i])
	{
		cmd->environ[i] = ft_strdup(temp[i]);
		i++;
	}
	cmd->environ[i++] = ft_strdup(envvar);
	cmd->environ[i] = NULL;
	return (1);
}

int	error_check_add_envv(char *envvar)
{
	int	i;
	int	q;

	q = 0;
	i = 0;
	if (envvar[0] == '?' && envvar[1] == '=')
		return (0);
	if (envvar[0] >= '0' && envvar[0] <= '9')
		return (1);
	while (envvar[i])
	{
		if (envvar[i] == '=')
			q++;
		i++;
	}
	if (q != 1)
		return (1);
	if (envv_naming_check(envvar))
		return (1);
	return (0);
}

int	update_envv(char *envvar, t_cmd *cmd)
{
	int	i;
	int	len;

	len = envvar_len(envvar);
	i = 0;
	while (cmd->environ[i])
	{
		if (ft_strncmp(envvar, cmd->environ[i], len) == 0
			&& cmd->environ[i][len] == '=')
		{
			cmd->environ[i] = ft_strdup(envvar);
			return (1);
		}
		i++;
	}
	return (0);
}
