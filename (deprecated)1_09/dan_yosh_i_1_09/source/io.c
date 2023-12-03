/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:09:33 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/03 13:12:06 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	in(t_cmd *cmd, int i)
{
	if (is_valid_filename(cmd->tokens[i + 1]))
	{
		if (cmd->io_cross_in)
			return (0);
		if (cmd->io_dup_in)
			return (0);
		cmd->io_dup_in = 1;
		cmd->fd_stdin = dup(STDIN_FILENO);
		cmd->fd_infile = open(cmd->tokens[i + 1], O_RDONLY);
		if (cmd->fd_infile == -1)
			perror("Error: INFILE OPEN");
		dup2(cmd->fd_infile, STDIN_FILENO);
		return (1);
	}
	return (0);
}

int	in_here(t_cmd *cmd, int i)
{
	if (cmd->io_cross_in)
		return (0);
	if (cmd->io_dup_in)
		return (0);
	cmd->io_dup_in = 1;
	cmd->fd_stdin = dup(STDIN_FILENO);
	cmd->here_prompt = strdup("writenow > ");
	cmd->here_eof = strdup(cmd->tokens[i + 1]);
	cmd->fd_here = open(ft_strjoin(retrv_envv("HOME", cmd),
				"/.temporary_heredoc"), O_CREAT | O_RDWR | O_TRUNC, 0760);
	if (cmd->fd_here == -1)
		perror("Error: INFILE OPEN");
	write_2_fd_here(cmd);
	lseek(cmd->fd_here, 0, SEEK_SET);
	dup2(cmd->fd_here, STDIN_FILENO);
	return (1);
}

void	write_2_fd_here(t_cmd *cmd)
{
	cmd->here_buffer = malloc(1);
	sig_read_handle(cmd);
	while (strcmp(cmd->here_buffer, cmd->here_eof) != 0)
	{
		cmd->here_buffer = readline(cmd->here_prompt);
		if (cmd->here_buffer)
		{
			if (ft_strcmp(cmd->here_buffer, cmd->here_eof) == 0)
				break ;
			write(cmd->fd_here, cmd->here_buffer, ft_strlen(cmd->here_buffer));
			write(cmd->fd_here, "\n", 1);
		}
		else
			exit(-1);
	}
	free(cmd->here_buffer);
}

int	out(t_cmd *cmd, int i)
{
	if (is_valid_filename(cmd->tokens[i + 1]))
	{
		if (cmd->io_dup_out)
			return (0);
		cmd->io_dup_out = 1;
		cmd->fd_stdout = dup(STDOUT_FILENO);
		cmd->fd_outfile = open(cmd->tokens[i + 1],
				O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (cmd->fd_outfile == -1)
			perror("Error: OUTFILE OPEN");
		dup2(cmd->fd_outfile, STDOUT_FILENO);
		return (1);
	}
	return (0);
}

int	out_append(t_cmd *cmd, int i)
{
	if (is_valid_filename(cmd->tokens[i + 1]))
	{
		if (cmd->io_dup_out)
			return (0);
		cmd->io_dup_out = 1;
		cmd->fd_stdout = dup(STDOUT_FILENO);
		cmd->fd_outfile = open(cmd->tokens[i + 1],
				O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (cmd->fd_stdout == -1)
			perror("Error: OUTFILE OPEN");
		dup2(cmd->fd_outfile, STDOUT_FILENO);
		return (1);
	}
	return (0);
}
