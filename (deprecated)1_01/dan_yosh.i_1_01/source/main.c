/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:29:32 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/18 13:18:43 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

extern int	g_estatus;

int	main(void)
{
	char	input[INLEN];
	int		flag;
	t_cmd	*cmd;
	int		hack;

	cmd = malloc(sizeof(t_cmd));
	flag = BUILTINCMD;
	g_estatus = 0;
	entry_message();
	hack = 0;
	while (1)
	{
		if (!hack)
		{
			hack = 1;
			continue ;
		}
		if (!cmd_input(input))
			continue ;
		flag = parse_input(input, cmd);
		if (flag > 0)
			run(flag, cmd);
	}
	free(cmd);
	return (0);
}
