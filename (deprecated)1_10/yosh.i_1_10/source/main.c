/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:29:32 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/03 15:57:55 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	init_struct(t_cmd **cmd, t_prompt **prompt, t_norm **norm)
{
	*prompt = malloc(sizeof(t_prompt));
	*cmd = malloc(sizeof(t_cmd));
	(*cmd)->n = malloc(sizeof(t_norm));
	*norm = malloc(sizeof(t_norm));
	(*cmd)->flag = BUILTINCMD;
	(*cmd)->estatus = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd		*cmd;
	t_prompt	*prompt;
	t_norm		*norm;

	if (argc != 1)
		return (ft_strlen(argv[0]));
	init_struct(&cmd, &prompt, &norm);
	copy_environ(envp, cmd);
	load_history(cmd);
	entry_message();
	while (1)
	{
		if (!cmd_input(cmd, prompt))
			continue ;
		cmd->expanded = (char *)malloc(sizeof(char) * INLEN);
		cmd->expanded = expander(cmd->input, cmd);
		cmd->flag = parse_input(cmd, norm);
		if (cmd->flag > 0)
			run(cmd);
		save_history(cmd);
	}
}
