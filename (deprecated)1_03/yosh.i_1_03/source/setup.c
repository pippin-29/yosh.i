/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:29:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/09 14:16:15 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

extern int	g_estatus;

void	entry_message(void)
{
	printf("⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥ yosh.i  🔐Your Shell🔓");
	printf(" ⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤\n");
	printf("___________________________interactive");
	printf("__________________________\n");
	sleep(1);
}

int	cmd_input(char *str, t_prompt *prompt)
{
	char	*buffer;

	sig_read_handle();
	set_prompt(prompt);
	buffer = readline(prompt->prompt);
	if (buffer)
	{
		sig_text_handle(buffer);
		add_history(buffer);
		ft_strlcpy(str, buffer, INLEN);
		return (ft_strlen(str));
	}
	if (!buffer)
	{
		printf("exit");
		exit(1);
	}
	return (0);
}
