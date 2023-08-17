/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:29:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/18 09:12:21 by dhadding         ###   ########.fr       */
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

	buffer = readline("[🩷 > ");
	if (ft_strlen(buffer))
	{
		add_history(buffer);
		ft_strlcpy(str, buffer, INLEN);
		return (ft_strlen(str));
	} else
		return (0);
}

void print_prompt()
{

	char cwd[1024];
	char hostname[128];
	char *username;

	getcwd(cwd, sizeof (cwd));
	gethostname(hostname, sizeof (hostname));
	username = getenv("USER");

	ft_printf("🏠%s@%s :: %s/ ", username, hostname, basename(cwd));
}