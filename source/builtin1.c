/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 05:17:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/18 07:28:20 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int check_4_builtin(char **tokens)
{
	if (strcmp(tokens[0], "exit") == 0)
		exit(0);
	else if (strcmp(tokens[0], "cd") == 0)
		return (cd(tokens));
	else if (strcmp(tokens[0], "pwd") == 0)
		return (pwd());
	else if (strcmp(tokens[0], "export") == 0)
		return (export(tokens));
	else if (strcmp(tokens[0], "unset") == 0)
		return (unset(tokens));
	else if (strcmp(tokens[0], "env") == 0)
		return (env());
	else if (strcmp(tokens[0], "echo") == 0)
		return (echo(tokens));
	return (0);
}

// int echo(char *option, char **strings)
// {

// 	return (1);
// }

// int cd(char *path)
// {

// 	return (1);
// }

// int pwd(void)
// {

// 	return (1);
// }

// int export(char *var)
// {

// 	return (1);
// }
