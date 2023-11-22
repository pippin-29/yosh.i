/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd-ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:43:19 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/15 14:55:27 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

#define APPEND ">>\0"
#define PIPE "|\0"
#define HERE "<<\0"
#define IN "<\0"
#define OUT ">\0"

void	run_complexcmd(t_cmd *cmd)
{
	t_ops	*ops;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ops = malloc(sizeof(t_ops));
	while (cmd->tokens[i])
	{
		if (is_op(cmd->tokens[i], cmd->pipredir[j]))
		{

			cmd->cmd = cmd_group(&cmd->tokens[i + 1], cmd->pipredir[j + 1]);
			// if (strcmp(cmd->pipredir[j], APPEND) == 0)
			// 	out_append(cmd, j);
			if (strcmp(cmd->pipredir[j], HERE) == 0)
				in_here(cmd, ops);
			else if (strcmp(cmd->pipredir[j], OUT) == 0)
				out(cmd, ops);
			// else if (strcmp(cmd->pipredir[j], IN) == 0)
			// 	in(cmd, j);
			j++; 
			
		}
		if (check_if_program_2_run(cmd->pipredir[j], cmd->cmd[0]))
			runf(cmd);
		i++;
	}
	dup2(ops->fd_out, STDOUT_FILENO);
	dup2(ops->fd_in, STDIN_FILENO);
}

int	check_if_program_2_run(char *op, char *cmd_alpha)
{
	if (op)
		if (is_op(op, PIPE))
			return (1);
	(void)cmd_alpha;

	return (0);
}

void	runf(t_cmd *cmd)
{
	pid_t	pid;
	printf("check\n");
	pid = fork();
	if (pid == -1)
		fprintf(stdout, "Could not create child process.");
	else if (pid == 0)
	{
		if (execve(get_prog_path(cmd->cmd[0]), cmd->cmd, environ) == -1)
		{
			perror(ft_strjoin("yosh.i: command not found: ", cmd->cmd[0]));
			exit(errno);
		}
	}
	waitpid(pid, &cmd->estatus, WCONTINUED);
}

int count_2_pipredir(char **tokens, char *op)
{
	int i;

	i = 0;
	
	while (tokens[i])
	{
		
		if (op)
			if ((strcmp(tokens[i], op) == 0))
				return (i);
		i++;
	}
	return (i);
}

char **cmd_group(char **token_group, char *op)
{
	char **cmd_group;
	int	i;
	int c;

	i = 0;
	c = count_2_pipredir(token_group, op);
	cmd_group = malloc(sizeof(char *) * (c + 1));
	
	while (c)
	{
		cmd_group[i] = strdup(token_group[i]);
		printf("%s %d\n", cmd_group[i], i);
		i++;
		c--;
	}
	cmd_group[i] = NULL;
	return (cmd_group);
}

int	is_op(char *token, char *op)
{
	if (op)
	{
		if (strcmp(token, op) == 0)
		return (1);
	}
	return (0);
}

// int	in(t_cmd *cmd, t_ops *ops)
// {
// 	ops->fd_in = open(cmd->cmd[0], O_RDONLY);
// 	if (!ops->fd_in)
// 		perror("Error: INFILE OPEN");
// 	dup2(ops->fd_in, STDIN_FILENO);
// }

void in_here(t_cmd *cmd, t_ops *ops)
{
	int size;

	size = 0;

	ops->fd_in = dup(STDIN_FILENO);
	ops->here_prompt = strdup("writenow > ");
	ops->here_EOF = strdup(cmd->cmd[0]);
	cmd->cmd = (cmd->cmd + 1);
	ops->fd_here = open(".temporary_heredoc", O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (ops->fd_here == -1)
		perror("Error: INFILE OPEN");
	size = write_2_fd_here(ops);
	lseek(ops->fd_here, 0, SEEK_SET);
	dup2(ops->fd_here, STDIN_FILENO);
}

int write_2_fd_here(t_ops *ops)
{
	char *buffer;
	int size;

	size = 0;
	buffer = malloc(1);
	while (strcmp(buffer, ops->here_EOF) != 0)
	{
		buffer = readline(ops->here_prompt);
		size += strlen(buffer);
		if(strcmp(buffer, ops->here_EOF) == 0)
			break ;
		write(ops->fd_here, buffer, ft_strlen(buffer));
		write(ops->fd_here, "\n", 1);
	}
	free(buffer);
	return size;
}

void	out(t_cmd *cmd, t_ops *ops)
{
	ops->fd_out = dup(STDOUT_FILENO);
	dup2(ops->fd_out_red, STDOUT_FILENO);
	ops->fd_out_red = open(cmd->cmd[0], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (ops->fd_out_red == -1)
		perror("Error: OUTFILE OPEN");
	close(ops->fd_out);
}

// int	out_append(t_cmd *cmd, t_ops *ops)
// {
// 	ops->fd_out = open(cmd->cmd[0], O_CREAT | O_WRONLY | O_APPEND);
// 	if (!ops->fd_out)
// 		perror("Error: OUTFILE OPEN");
// 	dup2(ops->fd_out, STDOUT_FILENO);
// }

// bool	piper(t_cmd *cmd, t_ops *ops)
// {
// 	if (!pipe(ops->pipe))
// 		return (false);
// 	ops->pid = fork();
// 	if (ops->pid < 0)
// 		return (false);
// 	else if (ops->pid == 0)
	
	
// 	return (true);
// }

// void child(t_cmd *cmd, t_ops *ops, int child_no, bool flag)
// {
// 	cmd->cmd = cmd_group(cmd->tokens[child_no]);
// 	if (execve(get_prog_path(cmd->cmd[0]), cmd->cmd, environ) == -1 && flag == FALSE)
// 	{
// 		perror(ft_strjoin("yosh.i: command not found: ", cmd->cmd[0]));
// 		exit(errno);
// 	}
// 	waitpid(ops->pid, &cmd->estatus, WCONTINUED);
// }

