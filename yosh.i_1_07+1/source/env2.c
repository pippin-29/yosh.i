/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:10:30 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/30 10:25:20 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"
extern char **environ2;

int	rm_envv(char *envvar)
{
	int	i;

	i = 0;
	while(environ2[i])
	{
		if (ft_strncmp(envvar, environ2[i],ft_strlen(envvar)) == 0)
			if (environ2[i][ft_strlen(envvar)] == '=')
				return (contract_env(environ2, i));
		i++;
	}
	return (0);
}

int	contract_env(char **tda, int index)
{
	int		i;
	int		q;

	i = 0;
	q = 0;
	environ2 = malloc(sizeof(char *) * (ft_lstlen(tda)));
	if (!environ2)
		return (0);
	while (tda[q])
	{
		if (i == index)
			q++;
		environ2[i] = ft_strdup(tda[q]);
		i++;
		q++;
	}
	environ2[i] = NULL;
	return (1);
}

int	add_envv(char *envvar)
{
	int	i;
	char **temp;

	i = 0;
	
	if (error_check_add_envv(envvar))
		return (-1);
	if (update_envv(envvar))
		return (1);
	temp = ft_tabdup(environ2);
	environ2 = malloc(sizeof(char *) * (ft_lstlen(temp) + 2));
	while (temp[i])
	{
		environ2[i] = ft_strdup(temp[i]);
		i++;
	}
	environ2[i++] = ft_strdup(envvar);
	environ2[i] = NULL;
	return (1);
}

int error_check_add_envv(char *envvar)
{
	int	i;
	int q;

	q = 0;
	i = 0;
	if (envvar[0] == '?' && envvar[1] == '=')
		return (0);
	if (envvar[0] >= '0' && envvar[0] <= '9')
		return (1);
	while(envvar[i])
		if (envvar[i] == '=')
			q++;
	if (q != 1)
		return (1);
	q = i;
	i = 0;
	while (envvar[i])
	{
		if (i == q)
			i++;
		if (envvar[i] != '_' && !ft_isalpha(envvar[i]) && !ft_isdigit(envvar[i]))
			return (1);
		i++;
	}
	return (0);
}

int	update_envv(char *envvar)
{
	int i;
	int len;

	len = envvar_len(envvar);
	i = 0;
	while(environ2[i])
	{
		if (ft_strncmp(envvar, environ2[i], len) == 0)
			if (environ2[i][len] == '=')
			{
				environ2[i] = ft_strdup(envvar);
				return (1);
			}	
		i++;
	}
	return (0);
}

