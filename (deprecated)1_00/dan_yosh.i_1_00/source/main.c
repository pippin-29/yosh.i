/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:29:32 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/09 15:24:44 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	main(void)
{
		char	input[INLEN];
		int		flag;
		t_cmd	*cmd;

		cmd = malloc(sizeof (t_cmd)); 
		flag = BUILTINCMD;
		init_yosh_i();
		while (1)
		{
			print_prompt();
			if (!cmd_input(input))
				continue ;
			flag = parse_input(input, cmd);
			if (flag > 0)
				run(flag, cmd);
		}
		free(cmd);

		return (0);
} 