/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <dhadding@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:29:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/05 13:31:51 by dhadding         ###   ########.fr       */
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

int	cmd_input(char *str)
{
	char	*buffer;

	buffer = readline("[ > ");
	if (ft_strlen(buffer))
	{
		add_history(buffer);
		ft_strlcpy(str, buffer, INLEN);
		return (ft_strlen(str));
	}
	else
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
