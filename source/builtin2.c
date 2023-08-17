/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:18:35 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/18 09:16:56 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int unset(char **tokens)
{
	if (!tokens[2])
		if (unsetenv(tokens[1]) == -1)
			ft_printf("Failed\n");
	return (1);
}

int env(void)
{
	system("env");
	return (1);
}
