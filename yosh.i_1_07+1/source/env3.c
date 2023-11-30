/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:06:55 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/30 10:52:27 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int envvar_len(char *envvar)
{
	int i;

	i = 0;
	while (envvar[i] != '=')
		i++;
	return (i);
}

char *retrvv_cwd(char *oldpath, char *newpath)
{
	if (newpath[0] == '/')
		if (access(newpath, F_OK) == 0)
			return (newpath);
	if (newpath[0] == '.')
		if (access(newpath, F_OK) == 0)
			return (relative_resolution(oldpath, newpath));
}

char *relative_resolution(char *oldpath, char *newpath)
{
	int i;
	int q;

	i = 0;
	q = 0;
	while(newpath[i])
	{
		
	}
}