/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:14:16 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/09 15:24:34 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

char	*get_prog_path(char *prog_name)
{
	char **paths;
	int	i;

	i = 0;
	paths = ft_split(getenv("PATH"), ':');

	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		paths[i] = ft_strjoin(paths[i], prog_name);
		if (access(paths[i], F_OK) == 0)
			return (paths[i]);
		i++;
	} 
	return (NULL);	
}