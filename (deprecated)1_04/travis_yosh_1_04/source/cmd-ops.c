/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd-ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:43:19 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/14 11:10:22 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"
/*
int	count_group(char **token_group, char *op)
{
	int i;

	i = 0;
	while (token_group[i] || (strcmp(token_group[i], op) == 0))
		i++;
	return (i);
}

char **cmd_group(char **token_group, t_ops *op)
{
	char **cmd_group;
	int	c;
	int	i;

	i = 0;
	c = count_group(token_group, op);
	cmd_group = malloc(sizeof(char *) * (c + 1));
	while (c)
	{
		cmd_group[i] = strdup(token_group[i]);
		i++;
		c--;
	}
	return (cmd_group);
}

int	is_op(char *token, char *op)
{
	if (strcmp(token, op) == 0)
		return (1);
	return (0);
}

int	in(t_cmd *cmd, t_ops *ops)
{
	ops->fd_in = open(cmd->cmd[0], O_RDONLY);
	if (!ops->fd_in)
		perror("Error: INFILE OPEN");
	return (dup2(ops->fd_in, STDIN_FILENO));
}

int	in_here(t_cmd *cmd, t_ops *ops)
{
	ops->here_prompt = strdup("writenow:");
	ops->heredoc = true;

	ops->fd_in_here = open(cmd->cmd[0], O_RDONLY);
	if (!ops->fd_in)
		perror("Error: INFILE OPEN");
	return (dup2(ops->fd_in, STDIN_FILENO));
}

int	out(t_cmd *cmd, t_ops *ops)
{
	ops->fd_out = open(cmd->cmd[0], O_CREAT | O_WRONLY | O_TRUNC);
	if (!ops->fd_out)
		perror("Error: OUTFILE OPEN");
	return (dup2(ops->fd_out, STDOUT_FILENO));
}

int	out_append(t_cmd *cmd, t_ops *ops)
{
	ops->fd_out = open(cmd->cmd[0], O_CREAT | O_WRONLY | O_APPEND);
	if (!ops->fd_out)
		perror("Error: OUTFILE OPEN");
	return (dup2(ops->fd_out, STDOUT_FILENO));
}

void child(t_cmd *cmd, t_ops *ops, int child_no, bool flag)
{
	pipe(ops->pipe);
	cmd->cmd[child_no] = cmd_group(cmd->tokens, ops);
	if (flag == false)
	{
		dup2(ops->pipe[1], 1);
		close (ops->pipe[0]);
		if (execve(get_prog_path(cmd->cmd[child_no]), cmd->cmd, environ) == -1)
		{
			perror(ft_strjoin("yosh.i: command not found: ", cmd->cmd[0]));
			exit(errno);
		}
	}
	if (flag == true)
	{
		dup2(ops->pipe[0], STDIN_FILENO);
		close (ops->pipe[1]);
		printf("cheese");
		if (execve(get_prog_path(cmd->cmd[child_no + 1]), cmd->cmd, environ) == -1)
		{
			perror(ft_strjoin("yosh.i: command not found: ", cmd->cmd[0]));
			exit(errno);
		}
	}
}

void	run_complexcmd(t_cmd *cmd)
{
	t_ops	*ops;
	int		i;
	int		j;
	bool	flag;

	ops = malloc(sizeof(t_ops));
	flag = false;
	i = 0;
	j = 0;
	while (cmd->tokens[i])
	{
		child(cmd, ops, i, false);
		if (is_op(cmd->tokens[i], cmd->pipredir[j]))
		{

			cmd->cmd = (&cmd->tokens[i + 1], cmd->pipredir[j]);
			if (strcmp(cmd->pipredir[j], ">>") == 0)
				flag = out_append(cmd, ops);
			else if (strcmp(cmd->pipredir[j], "<<") == 0)
				flag = in_here(cmd, ops);
			else if (strcmp(cmd->pipredir[j], ">") == 0)
				flag = out(cmd, ops);
			else if (strcmp(cmd->pipredir[j], "<") == 0)
				flag = in(cmd, ops);
			else if (strcmp(cmd->pipredir[j], "|") == 0)
				child(cmd, ops, i, true);
		}
			j++;
		if (!flag)
			return ;
		i++;
	}
}
*/