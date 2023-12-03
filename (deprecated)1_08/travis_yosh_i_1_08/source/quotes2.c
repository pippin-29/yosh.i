/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:07:31 by tpawson           #+#    #+#             */
/*   Updated: 2023/12/01 13:32:01 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

char	*dequote_str(char *s)
{
	char *res;
	int	i;
	int j;

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
	printf("%s", res);
	return (res);
}