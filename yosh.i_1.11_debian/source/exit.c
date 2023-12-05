/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:43:28 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/04 14:54:33 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	exitshell(t_cmd *cmd, t_norm *norm)
{
	unlink(cmd->temporary_heredoc);
	unlink(cmd->to_pipe);
	save_history(cmd);
	free_norm(norm);
	free_cmd(cmd);
	exit(0);
}
