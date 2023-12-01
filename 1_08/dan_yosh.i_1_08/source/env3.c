/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:06:55 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/30 14:24:23 by dhadding         ###   ########.fr       */
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
