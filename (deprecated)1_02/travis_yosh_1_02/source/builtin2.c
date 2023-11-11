/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:18:35 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/24 12:07:37 by dhadding         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (1);
}

int continue_w_error(char **tokens)
{
	if (strcmp(tokens[1], "unclosed") == 0)
	{
		printf("Quotes must be closed\n");
		return (1);
	}
	else
		return (1);
}
