/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:29:32 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/15 11:50:50 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	init_struct(t_cmd **cmd, t_prompt **prompt)
{
	*prompt = malloc(sizeof(t_prompt));
	*cmd = malloc(sizeof(t_cmd));
	(*cmd)->flag = BUILTINCMD;
	(*cmd)->estatus = 0;
}

int	main(void)
{
	t_cmd		*cmd;
	t_prompt	*prompt;

	load_history();
	init_struct(&cmd, &prompt);
	entry_message();
	while (1)
	{
		if (!cmd_input(cmd, prompt))
			continue ;
		cmd->expanded = (char *)malloc(sizeof(char) * INLEN);
		cmd->expanded = expander(cmd->input);
		cmd->flag = parse_input(cmd);
		if (cmd->flag > 0)
			run(cmd);
	}
	free(cmd);
	return (0);
}