/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:29:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/30 12:36:21 by dhadding         ###   ########.fr       */
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

int	cmd_input(char *str)
{
	char	*buffer;
	char	*prompt;

	sig_read_handle();
	prompt = set_prompt();
	buffer = readline(prompt);
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

char *set_prompt(void)
{
	char	cwd[1024];
	char	hostname[128];
	char	*username;
	char	*prompt;
	char	*exitstatus;

	exitstatus = ft_itoa(WEXITSTATUS(g_estatus));
	prompt = malloc(INLEN);
	getcwd(cwd, sizeof (cwd));
	gethostname(hostname, sizeof (hostname));
	username = retrv_envv("USER");

	snprintf(prompt, INLEN,  "🏠\001\e[1;96m\002%s\001\e", username);
	snprintf(prompt + strlen(prompt), INLEN, "[97m\002@\001\e[96m\002%s", hostname);
	snprintf(prompt + strlen(prompt), INLEN, "\001\e[97m\002 :: \001\e[96m\002");
	snprintf(prompt + strlen(prompt), INLEN,  "%s/\001\e[31m\002", basename(cwd));
	snprintf(prompt + strlen(prompt), INLEN, " [%d]\001\e[0;32m\002 💀>",
		WEXITSTATUS(g_estatus));
	if (putenv(ft_strjoin("?=", exitstatus)) == -1)
			printf("$? Not Assigned\n");
	return (prompt);
}