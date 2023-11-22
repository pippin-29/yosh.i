/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:29:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/20 07:45:22 by tpawson          ###   ########.fr       */
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
	int		flag;

	cmd->rl_yn = 1;
	sig_read_handle(cmd);
	set_prompt(cmd, prompt);
	buffer = readline(prompt->prompt);
	if (buffer)
	{
		if (is_whitespace(buffer))
			return (0);
		add_history(buffer);
		ft_strlcpy(cmd->input, buffer, INLEN);
		flag = 0;
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
