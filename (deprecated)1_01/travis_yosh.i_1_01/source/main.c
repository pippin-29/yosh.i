/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:29:32 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/06 10:17:34 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	main(void)
{
		char	input[INLEN];
		char	*expanded;
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
			expanded = (char *)malloc(sizeof(char) * INLEN);
			expanded = expander(input);
			flag = parse_input(expanded, cmd);
			if (flag > 0)
				run(flag, cmd);
		}
		free(cmd);

		return (0);
} 