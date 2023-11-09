/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:18:35 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/11 10:58:10 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

extern char **environ;

int	unset(char **tokens)
{
	if (!tokens[2])
		if (unsetenv(tokens[1]) == -1)
			ft_printf("Failed\n");
	return (1);
}

int	env(void)
{
	int	i;

	i = 0;
	while (environ[i])
	{
		ft_printf("%s\n", environ[i]);
		i++;
	}
	return (1);
}
