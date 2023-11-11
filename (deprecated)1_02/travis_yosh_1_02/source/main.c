/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:29:32 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/06 11:48:07 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

extern int	g_estatus;

int	main(void)
{
	char	input[INLEN];
	int		flag;
	char	*expanded;
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
		expanded = (char *)malloc(sizeof(char) * INLEN);
		expanded = expander(input);
		flag = parse_input(expanded, cmd);
		if (flag > 0)
			run(flag, cmd);
	}
	free(cmd);
	return (0);
}
