/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 06:52:13 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/04 15:16:52 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	free_2d_char(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_cmd_help(t_cmd *cmd)
{
	if (cmd && cmd->cmd)
		free_2d_char(cmd->cmd);
	if (cmd && cmd->environ)
		free_2d_char(cmd->environ);
	if (cmd && cmd->tokens)
		free_2d_char(cmd->tokens);
	if (cmd && cmd->pipredir)
		free_2d_char(cmd->pipredir);
}

void	free_cmd(t_cmd *cmd)
{
	if (cmd && cmd->here_prompt)
		free(cmd->here_prompt);
	if (cmd && cmd->here_eof)
		free(cmd->here_eof);
	if (cmd && cmd->here_buffer)
		free(cmd->here_buffer);
	if (cmd && cmd->exitstatuskey)
		free(cmd->exitstatuskey);
	if (cmd && cmd->to_pipe)
		free(cmd->to_pipe);
	if (cmd && cmd->temporary_heredoc)
		free(cmd->temporary_heredoc);
	if (cmd && cmd->yosh_history)
		free(cmd->yosh_history);
	if (cmd && cmd->home)
		free(cmd->home);
	free_norm(cmd->n);
	free_prompt(cmd->prompt);
	close_files(cmd);
	free(cmd);
}

void	free_norm(t_norm *norm)
{
	if (norm && norm->act)
		free(norm->act);
	if (norm && norm->tmp)
		free(norm->tmp);
	if (norm)
		free(norm);
}

void	free_prompt(t_prompt *prompt)
{
	free(prompt->cyan);
	free(prompt->username);
	free(prompt->white);
	free(prompt->cwd);
	free(prompt->red);
	free(prompt->exitstatus);
	free(prompt->out);
	free(prompt->green);
	free(prompt->prompt);
	free(prompt);
}
