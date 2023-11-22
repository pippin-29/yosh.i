/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:18:35 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/22 01:31:54 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

extern char	**environ;

int	unset(char **tokens )
{
	if (!tokens[2])
		if (unsetenv(tokens[1]) == -1)
			printf("Failed\n");
	return (1);
}

int	env(void)
{
	print_list_2d(environ);
	return (1);
}

int	continue_w_error(char **tokens)
{
	if (tokens[1] && ft_strcmp(tokens[1], "unclosed") == 0)
	{
		printf("Quotes must be closed\n");
		return (1);
	}
	else
		return (1);
}
