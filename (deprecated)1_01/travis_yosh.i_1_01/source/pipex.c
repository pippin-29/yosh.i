/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:28:05 by tpawson           #+#    #+#             */
/*   Updated: 2023/10/30 12:16:38 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*path;
	char	*res;

	i = 0;
	if (!env)
		exit(1);
	while (env[i] && ft_strnstr(env[i], "PATH=", 5) == 0)
		i++;
	if (!(env[i]))
		exit(1);
	paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		res = ft_strjoin(path, cmd);
		if (access(res, F_OK) == 0)
			return (res);
		else
			free(res);
	}
	return (0);
}

char	*ft_pathpos(char *cmd, char **env)
{
	int		i;
	int		k;
	char	*pathpos;
	char	*res;
	int		len;

	i = 0;
	k = -1;
	if (!(env))
		exit(1);
	while (env[i] && ft_strnstr(env[i], "PWD=", 4) == 0)
		i++;
	if (!(env[i]))
		exit(0);
	len = (ft_strlen(env[i]) - 4);
	pathpos = (char *)malloc(sizeof(char) * len);
	while (++k < len)
		pathpos[k] = env[i][k + 4];
	pathpos = ft_strjoin(pathpos, "/");
	res = ft_strjoin(pathpos, cmd);
	if (access(res, F_OK) == 0)
		return (res);
	else
		free(res);
	exit(0);
}

void	ft_cmd(char *argv, char **env)
{
	char		**cmd1;
	char		**cmd2;
	char		*path;
	int			i;

	i = 0;
	cmd1 = ft_split(argv, ' ');
	cmd2 = ft_split(argv, ' ');
	if (access(cmd1[0], X_OK) == 0)
	{
		cmd1 = ft_split(argv, '/');
		while (cmd1[i])
			i++;
		cmd1 = ft_split(cmd1[i - 1], ' ');
		execve(cmd2[0], cmd1, env);
	}
	path = ft_path(cmd1[0], env);
	if (!(path))
		path = ft_pathpos(cmd1[0], env);
	if (execve(path, cmd1, env) == -1)
	{
		perror("CMD ERROR: ");
		exit(1);
	}
}

void	ft_child(char *path, char **env, int *fd)
{
	int	in;

	in = open(path, O_RDONLY);
	dup2(fd[1], 1);
	dup2(in, 0);
	close(fd[0]);
	ft_cmd(path, env);
}

void	ft_par(char *path, char **env, int *fd)
{
	int	out;

	out = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	dup2(fd[0], 0);
	dup2(out, 1);
	close(fd[1]);
	ft_cmd(path, env);
}