/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:38:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/17 10:46:54 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void run(int flag, t_cmd *cmd)
{
	if (flag == SIMPLECMD)
		run_simplecmd(cmd);
	if (flag == COMPLEXCMD)
		run_complex_cmd(cmd);
	free(cmd->cmds);
	free(cmd->pipredir);
}

void run_simplecmd(t_cmd *cmd)
{

}

void run_complexcmd(t_cmd *cmd)
{
	
}