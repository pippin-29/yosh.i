/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:42:46 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/22 01:38:32 by tpawson          ###   ########.fr       */
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
	prompt->red = ft_strdup("\001\e[1;31m\002");
	prompt->cyan = ft_strdup("\001\e[0;36m\002");
	prompt->green = ft_strdup("\001\e[0;32m\002");
	prompt->white = ft_strdup("\001\e[1;37m\002");
	prompt->out = ft_strdup(">");
	store_prompt(prompt);
	if (putenv(ft_strjoin("?=", prompt->exitstatus)) == -1)
		printf("$? Not Assigned\n");
}

void	store_prompt(t_prompt *prompt)
{
	prompt->prompt = strjoin_e(17,
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
			"] 💀",
			prompt->out,
			prompt->green);
}
