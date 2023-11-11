/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:17:37 by tpawson           #+#    #+#             */
/*   Updated: 2023/10/18 12:20:56 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	sig_ctrlc(int sig)
{
	if (sig)
	{
		write(2, "\n", 1);
		// print_prompt();
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	sig_read_handle(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sig_ctrlc);
}

void	sig_text_handle(char *s)
{
	if (s)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}
