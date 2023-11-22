/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:29:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/15 14:14:11 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	entry_message(void)
{
	printf("⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥⇥ yosh.i  🔐Your Shell🔓");
	printf(" ⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤⇤\n");
	printf("___________________________interactive");
	printf("__________________________\n");
	sleep(1);
}

int	cmd_input(t_cmd *cmd, t_prompt *prompt)
{
	char	*buffer;

	sig_read_handle();
	set_prompt(cmd, prompt);
	buffer = readline(prompt->prompt);
	if (buffer)
	{
		if (is_whitespace(buffer))
			return (0);
		
		add_history(buffer);
		ft_strlcpy(cmd->input, buffer, INLEN);
		return (ft_strlen(cmd->input));
	}
	else if (!buffer)
	{
		save_history();
		printf("exiting\n");
		exit(1);
	}
	return (0);
}
