/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:10:30 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/29 16:46:54 by dhadding         ###   ########.fr       */
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
		if (ft_strncmp(envvar, environ2[i],ft_strlen(envvar)))
			if (environ2[i][ft_strlen(envvar)] == '=')
				return (contract_2d_char(environ2, i));
		i++;
	}
	return (0);
}

int	contract_2d_char(char **tda, int index)
{
	char	**tda_new;
	int		i;
	int		q;

	i = 0;
	q = 0;
	tda_new = malloc(sizeof(char *) * (ft_lstlen(tda)));
	if (!tda_new)
		return (0);
	while (tda[i])
	{
		if (i == index)
			q++;
		tda_new[i] = ft_strdup(tda[q]);
		i++;
		q++;
	}
	tda_new[i] = NULL;
	tda = tda_new;
	return (1);
}