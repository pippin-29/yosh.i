/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:29:32 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/30 20:12:17 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

extern char	**environ;

void	init_struct(t_cmd **cmd, t_prompt **prompt, t_norm **norm)
{
	*prompt = malloc(sizeof(t_prompt));
	*cmd = malloc(sizeof(t_cmd));
	*norm = malloc(sizeof(t_norm));
	(*cmd)->flag = BUILTINCMD;
	(*cmd)->estatus = 0;
}

int	main(void)
{
	t_cmd		*cmd;
	t_prompt	*prompt;
	t_norm		*norm;

	copy_environ(environ);
	init_struct(&cmd, &prompt, &norm);
	load_history();
	entry_message();
	while (1)
	{
		if (!cmd_input(cmd, prompt))
			continue ;
		cmd->expanded = (char *)malloc(sizeof(char) * INLEN);
		cmd->expanded = expander(cmd->input, norm);
		cmd->flag = parse_input(cmd, norm);
		if (cmd->flag > 0)
			run(cmd);
	}
}
