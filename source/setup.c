/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:29:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/16 12:58:30 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void init_yosh_i()
{
	system("clear");
	ft_printf(">>>>>>>>>>>>>> yosh.i (Your Shell) ||||||||||||||||||\n");
	ft_printf("______________________||||||||||||___________________\n");
	ft_printf("_____You Are Liable___------------___________________\n");
	ft_printf("_____________________________________________________\n");
	
	sleep(1);
}

int	cmd_input(char *str)
{
	char *buffer;

	buffer = readline(">>> ");
	if (ft_strlen(buffer))
	{
		add_history(buffer);
		str = ft_strdup(buffer);
		return (ft_strlen(buffer) - ft_strlen(str));
	} else
	{
		return (1);
	}
}

void print_prompt()
{

	char cwd[1024];
	char hostname[128];
	char *username;

	getcwd(cwd, sizeof (cwd));
	gethostname(hostname, sizeof (hostname));
	username = getenv("USER");

	ft_printf("\n%s@%s :: %s/ ", username, hostname, basename(cwd));
}