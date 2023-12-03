/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 08:09:33 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/01 15:25:46 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	in(t_cmd *cmd, int i)
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
	cmd->fd_here = open(ft_strjoin(retrv_envv("HOME"),
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
	char	*buffer;

	buffer = malloc(1);
	while (strcmp(buffer, cmd->here_eof) != 0)
	{
		buffer = readline(cmd->here_prompt);
		if (ft_strcmp(buffer, cmd->here_eof) == 0)
			break ;
		write(cmd->fd_here, buffer, ft_strlen(buffer));
		write(cmd->fd_here, "\n", 1);
	}
	free(buffer);
}

int	out(t_cmd *cmd, int i)
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

int	out_append(t_cmd *cmd, int i)
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
