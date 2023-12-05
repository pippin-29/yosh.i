/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 09:25:11 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/04 15:06:25 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	is_valid_filename(char *input)
{
	int	i;

	i = 0;
	if (!input)
		return (0);
	while (input[i])
	{
		if (input[i] == '<'
			|| input[i] == '>'
			|| input[i] == '*'
			|| input[i] == '?'
			|| input[i] == '|')
		{
			printf("\e[1;31mPlease Exclude '<', '>', '|', '?' , '*' From");
			printf(" Filenames.\e[0;32m\n");
			return (0);
		}
		i++;
	}
	return (1);
}

void	close_files(t_cmd *cmd)
{
	close(cmd->fd_from_pipe);
	close(cmd->fd_here);
	close(cmd->fd_infile);
	close(cmd->fd_outfile);
	close(cmd->fd_stdin);
	close(cmd->fd_stdout);
	close(cmd->fd_to_pipe);
}
