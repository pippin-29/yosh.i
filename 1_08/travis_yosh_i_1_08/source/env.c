/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:14:16 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/30 14:24:46 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

extern char	**environ;
extern char	**g_environ2;

void	copy_environ(char **env)
{
	int	i;

	i = 0;
	g_environ2 = malloc(sizeof(char *) * (ft_lstlen(env) + 1));
	while (environ[i])
	{
		g_environ2[i] = strdup(env[i]);
		i++;
	}
	g_environ2[i] = NULL;
}

char	*get_prog_path(char *prog_name)
{
	char	**paths;
	char	*fallback;
	int		i;

	fallback = strdup(ft_strjoin("/usr/bin/", prog_name));
	if (path_attached(prog_name))
		return (prog_name);
	i = 0;
	paths = ft_split(retrv_envv("PATH"), ':');
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		paths[i] = ft_strjoin(paths[i], prog_name);
		if (access(paths[i], F_OK) == 0)
			return (paths[i]);
		i++;
	}
	return (fallback);
}

int	path_attached(char *prog_name)
{
	if (access(prog_name, F_OK) == 0)
		return (1);
	else
		return (0);
}

char	*retrv_envv(char *envvar)
{
	int		len;
	char	*out;
	int		e;

	e = 0;
	out = NULL;
	len = ft_strlen(envvar);
	while (g_environ2[e])
	{
		if (ft_strncmp(g_environ2[e], envvar, len) == 0)
		{
			out = env_grab_value(g_environ2[e], len);
			break ;
		}
		e++;
	}
	if (!out)
		return ("\0");
	return (out);
}

char	*env_grab_value(char *environitem, int len)
{
	char	*out;
	int		item_len;
	int		i;
	int		o;

	item_len = ft_strlen(environitem);
	i = len + 1;
	o = 0;
	out = malloc(sizeof(char) * (item_len - len + 1));
	while (environitem[i])
	{
		out[o] = environitem[i];
		o++;
		i++;
	}
	out[o] = '\0';
	return (out);
}
