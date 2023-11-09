/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:31:19 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/30 12:18:21 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/yosh_i.h"

void split_w_quotes(char *input, t_cmd *cmd)
{
	int wc;
	int i;
	int j;
	int k;
	printf("\nSQ:\n");
	
	if (cmd->squotes)
		print_int_list(cmd->sqi, cmd->sqc);

	printf("\nDQ:\n");
	if (cmd->dquotes)
		print_int_list(cmd->dqi, cmd->dqc);




	printf("\n\nends\n\n");
	return ;
	if (cmd->squotes || cmd->dquotes)
		log_spaces_2_ignore(input, cmd);
	
	wc = word_count(input, cmd);
	cmd->tokens = malloc(sizeof(char *) * (wc + 1));
	i = 0;
	j = 0;
	k = 0;
	while (i < wc)
	{
		while (input[j] == ' ')
			j++;
		input = &input[j];
		j = 0;
		while ((input[j] != ' ' && input[j]))
			j++;								/// stuck here, must ignore spaces between quotes.
		cmd->tokens[i++] = ft_strndup(input, j);
	}
	cmd->tokens[i] = 0;
	return ;
}

void ignore_spaces(char *input, t_cmd *cmd)
{
	int i;
	int c;
	bool sqflag = false;
	bool dqflag = false;
	int d = 0;
	int s = 0;

	i = 0;
	c = 0;
	cmd->sii = malloc(sizeof(int) * 64);
	while (input[i])
	{
		if (i == cmd->sqi[s])
		{
			sqflag = !sqflag;
			s++;
		}	
		else if (i == cmd->dqi[d])
		{
			dqflag = !dqflag;
			d++;
		}
		if (sqflag && dqflag)
		{
			if (input[i] == ' ')
				cmd->sii[c] = i;
		}
		i++;
	}
}

int word_count(char *input, t_cmd *cmd)
{
	int	wc;
	int	trigger;
	int i;
	int c;

	trigger = 0;
	wc = 0;
	i = 0;
	c = 0;
	while (input[i])
	{
		if (i != cmd->sii[c])
		{
			if (input[i] != ' ' && trigger == 0)
			{
				trigger = 1;
				wc++;
			}
			else if (input[i] == ' ')
				trigger = 0;
			i++;
		}
		else
			c++;
	}
	return (wc);
}
