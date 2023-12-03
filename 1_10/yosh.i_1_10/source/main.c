/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:29:32 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/03 13:28:36 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	init_struct(t_cmd **cmd, t_prompt **prompt, t_norm **norm)
{
	*prompt = malloc(sizeof(t_prompt));
	*cmd = malloc(sizeof(t_cmd));
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
		cmd->expanded = expander(cmd->input, norm, cmd);
		cmd->expanded = dequote_str(cmd->expanded);
		cmd->flag = parse_input(cmd, norm);
		if (cmd->flag > 0)
			run(cmd);
		save_history(cmd);
	}
}
