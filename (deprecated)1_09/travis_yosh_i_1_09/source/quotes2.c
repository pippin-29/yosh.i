/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:07:31 by tpawson           #+#    #+#             */
/*   Updated: 2023/12/01 15:22:59 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

char	*dequote_str(char *s)
{
	char	*res;
	int		i;
	int		j;

	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + (INLEN * INLEN)));
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == '\'' || s[i] == '"')
			i++;
		res[j++] = s[i++];
	}
	res[j] = '\0';
	return (res);
}
