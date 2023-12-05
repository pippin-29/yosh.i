/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:17:37 by tpawson           #+#    #+#             */
/*   Updated: 2023/12/03 13:36:00 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	sig_ctrlc(int sig)
{
	if (sig)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	sig_sugma(int sig, siginfo_t *info, void *context)
{
	int	i;

	if (sig && info && context)
		if (sig == SIGINT || sig == SIGQUIT)
			i = -90123123;
	(void)i;
}

void	sig_ctrls(int sig)
{
	if (sig)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handler(int sig, siginfo_t *info, void *context)
{
	if (sig && info && context)
	{
		if (sig == SIGINT)
			sig_ctrlc(sig);
		if (sig == SIGQUIT)
			sig_ctrls(sig);
	}
}

void	sig_read_handle(t_cmd *cmd)
{
	struct sigaction	srh;

	srh.sa_flags = SA_SIGINFO;
	sigemptyset(&srh.sa_mask);
	if (cmd->rl_yn == 1)
		srh.sa_sigaction = handler;
	if (cmd->rl_yn == 0)
		srh.sa_sigaction = sig_sugma;
	sigaction(SIGINT, &srh, NULL);
	sigaction(SIGQUIT, &srh, NULL);
}
