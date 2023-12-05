/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:29:32 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/04 14:50:53 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	create_filenames(t_cmd *cmd)
{
	cmd->home = retrv_envv("HOME", cmd);
	cmd->temporary_heredoc = ft_strjoin(cmd->home, "/.temporary_heredoc");
	cmd->yosh_history = ft_strjoin(cmd->home, "/.yosh_history");
	cmd->to_pipe = ft_strjoin(cmd->home, "/.to-pipe");
}

void	init_struct(t_cmd **cmd, t_norm **norm)
{
	*cmd = malloc(sizeof(t_cmd));
	(*cmd)->prompt = malloc(sizeof(t_prompt));
	(*cmd)->n = malloc(sizeof(t_norm));
	(*cmd)->n->act = NULL;
	(*cmd)->n->tmp = NULL;
	*norm = malloc(sizeof(t_norm));
	(*cmd)->flag = BUILTINCMD;
	(*cmd)->estatus = 0;
	(*cmd)->expanded = NULL;
	(*cmd)->cmd = NULL;
	(*cmd)->tokens = NULL;
	(*cmd)->pipredir = NULL;
	(*cmd)->here_prompt = NULL;
	(*cmd)->here_eof = NULL;
	(*cmd)->here_buffer = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd		*cmd;
	t_norm		*norm;

	if (argc != 1)
		return (ft_strlen(argv[0]));
	init_struct(&cmd, &norm);
	copy_environ(envp, cmd);
	create_filenames(cmd);
	load_history(cmd);
	entry_message();
	envp = NULL;
	while (1)
	{
		if (!cmd_input(cmd, norm))
			continue ;
		cmd->expanded = (char *)malloc(sizeof(char) * INLEN);
		cmd->expanded = expander(cmd->input, cmd);
		cmd->flag = parse_input(cmd, norm);
		if (cmd->flag > 0)
			run(cmd, norm);
		save_history(cmd);
	}
}
