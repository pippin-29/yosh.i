/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:17:37 by tpawson           #+#    #+#             */
/*   Updated: 2023/10/16 12:34:33 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	sig_ctrld(int sig)
{
	if (sig)
		write(2, "exit", 1);
	exit(1);
}

void	sig_ctrlc(int sig)
{
	if (sig)
	{
		write(2, "\n", 1);
		print_prompt();
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}