/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yoshrc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:56:30 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/01 13:54:14 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

// int read_yoshrc(t_cmd *cmd, t_norm *norm)
// {
// 	int		fd;
// 	char	*input_line;

// 	fd = open(ft_strjoin(retrv_envv("HOME"), "/.yoshrc"), O_RDONLY);
// 	input_line = get_next_line(fd);
// 	while (input_line)
// 	{
// 		if (!line_valid(input_line))
// 			continue;
// 		cmd->expanded = (char *)malloc(sizeof(char) * INLEN);
// 		cmd->expanded = expander(input_line, norm);
// 		cmd->flag = parse_input(cmd, norm);
// 		if (cmd->flag > 0)
// 			run(cmd);
// 		else if (cmd->flag == -1)
// 			printf("Builtins Cannot Be Interpreted In Conjunction With Redirections\n");
// 		input_line = get_next_line(fd);
// 	}
// 	return (1);
// }

// int	line_valid(char *input_line)
// {
// 	if (input_line[0] == '#')
// 		return (0);
// 	return (1);
// }