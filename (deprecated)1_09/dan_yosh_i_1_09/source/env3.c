/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:06:55 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/03 12:55:54 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	envvar_len(char *envvar)
{
	int	i;

	i = 0;
	while (envvar[i] != '=')
		i++;
	return (i);
}

int	envv_naming_check(char *envvar)
{
	int	i;

	i = 0;
	while (envvar[i] != '=')
	{
		if (envvar[i] != '_' && !ft_isalpha(envvar[i])
			&& !ft_isdigit(envvar[i]))
			return (1);
		i++;
	}
	return (0);
}

void	set_envvars(t_cmd *cmd)
{
	int	shlvl;

	shlvl = 0;
	add_envv("SHELL=$HOME/bin/yosh.i", cmd);
	if (retrv_envv("SHLVL", cmd)[0] == '\0')
		add_envv("SHLVL=1", cmd);
	else
	{
		shlvl = ft_atoi(retrv_envv("SHLVL", cmd));
		shlvl++;
		add_envv(ft_strjoin("SHLVL=", ft_itoa(shlvl)), cmd);
	}
}
