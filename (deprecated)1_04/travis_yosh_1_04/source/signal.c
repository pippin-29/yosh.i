/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:17:37 by tpawson           #+#    #+#             */
/*   Updated: 2023/11/15 14:06:06 by tpawson          ###   ########.fr       */
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

void	sig_sugma(int sig)
{
	if (sig == SIGQUIT)
		exit(0);
}

void	sig_doc_handle(void)
{
	signal(SIGQUIT, sig_sugma);
	signal(SIGINT, sig_sugma);
}
void	sig_read_handle(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_ctrlc);
}