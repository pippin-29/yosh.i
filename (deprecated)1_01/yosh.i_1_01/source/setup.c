/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:29:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/16 12:38:12 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	init_yosh_i(void)
{
	system("clear");
	ft_printf(">>>>>>>>>>>>>>>>>>>>> yosh.i  (Your Shell)");
	ft_printf(" <<<<<<<<<<<<<<<<<<<<<\n");
	ft_printf("___________________________interactive");
	ft_printf("__________________________\n");
	sleep(1);
}

void	sig_read_handle(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_ctrlc);
}

void	sig_text_handle(char *s)
{
	if (s)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}

int	cmd_input(char *str)
{
	char	*buffer;

	sig_read_handle();
	buffer = readline("[ > ");
	if (buffer)
	{
		sig_text_handle(buffer);
		add_history(buffer);
		ft_strlcpy(str, buffer, INLEN);
		return (ft_strlen(str));
	}
	if (!buffer)
	{
		printf("exit");
		exit(1);
	}
	return (0);
}

void	print_prompt(void)
{
	char	cwd[1024];
	char	hostname[128];
	char	*username;

	getcwd(cwd, sizeof (cwd));
	gethostname(hostname, sizeof (hostname));
	username = getenv("USER");
	ft_printf("🏠%s@%s :: %s/ ", username, hostname, basename(cwd));
}
