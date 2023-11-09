/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:35:06 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/30 12:19:20 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/yosh_i.h"

void log_single_quotes(char *input, t_cmd *cmd)
{
	int i;
	int c;
	int q;

	i = 0;
	c = 0;
	while (input[i])
	{
		if (input[i] == 39)
			c++;
		i++;
	}
	if (!c)
	{
		cmd->squotes = false;
		return ;
	}
	cmd->squotes = true;
	cmd->sqc = c;
	i = 0;
	cmd->sqi = malloc(sizeof(int) * c);
	q = 0;
	while (input[i])
	{
		if (input[i] == 39)
		{
			cmd->sqi[q] = i;
			q++;
		}
		i++;
	}
	i = 0;
	while(i < q)
	{
		printf("Single Quote %d Index = %d\n", i + 1, cmd->sqi[i]);
		i++;
	}
}

void log_double_quotes(char *input, t_cmd *cmd)
{
	int i;
	int c;
	int q;

	i = 0;
	c = 0;
	while (input[i])
	{
		if (input[i] == 34)
			c++;
		i++;
	}
	if (!c)
	{
		cmd->dquotes = false;
		return ;
	}
	cmd->dquotes = true;
	cmd->dqc = c;
	i = 0;
	cmd->dqi = malloc(sizeof(int) * c);
	q = 0;
	while (input[i])
	{
		if (input[i] == 34)
		{
			cmd->dqi[q] = i;
			q++;
		}
		i++;
	}
	i = 0;
	while(i < q)
	{
		printf("Double Quote %d Index = %d\n", i + 1, cmd->dqi[i]);
		i++;
	}
}