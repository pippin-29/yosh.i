/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:42:46 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/10 15:24:40 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	set_prompt(t_cmd *cmd, t_prompt *prompt)
{
	prompt->exitstatus = ft_itoa(WEXITSTATUS(cmd->estatus));
	prompt->prompt = malloc(INLEN);
	getcwd(prompt->cwd, sizeof (prompt->cwd));
	gethostname(prompt->hostname, sizeof (prompt->hostname));
	prompt->username = retrv_envv("USER");
	prompt->red = strdup("\e[1;31m");
	prompt->cyan = strdup("\e[0;36m");
	prompt->green = strdup("\e[0;32m");
	prompt->white = strdup("\e[1;37m");
	prompt->out = strdup(">");
	store_prompt(prompt);
	if (putenv(ft_strjoin("?=", prompt->exitstatus)) == -1)
		printf("$? Not Assigned\n");
}

void	store_prompt(t_prompt *prompt)
{
	prompt->prompt = strjoin_e(18,
			"🏠",
			prompt->cyan,
			prompt->username,
			prompt->white,
			"@",
			prompt->cyan,
			prompt->hostname,
			prompt->white,
			" :: ",
			prompt->cyan,
			basename(prompt->cwd),
			prompt->red,
			" [",
			prompt->exitstatus,
			"] ",
			"💀",
			prompt->out,
			prompt->green);
}
