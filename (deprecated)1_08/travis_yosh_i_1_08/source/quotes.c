/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 01:42:35 by tpawson           #+#    #+#             */
/*   Updated: 2023/12/01 12:38:33 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

int	sing_c(char *s, int index)
{
	int	i;
	int	one;
	int	two;

	i = 0;
	one = -1;
	two = -1;
	while (s[i] && s[i] != '\'')
		i++;
	one = i;
	if (s[i + 1] != '\0')
		i++;
	if (s[i])
		while (s[i] && s[i] != '\'')
			i++;
	if (s[i] == '\'')
		two = i;
	if (one == -1 || two == -1)
		return (0);
	if ((index > one) && (index < two))
		return (1);
	return (0);
}

int	doub_c(char *s, int index)
{
	int	i;
	int	one;
	int	two;

	i = 0;
	one = -1;
	two = -1;
	while (s[i] && s[i] != '"')
		i++;
	one = i;
	if (s[i + 1] != '\0')
		i++;
	if (s[i])
		while (s[i] && s[i] != '"')
			i++;
	if (s[i] == '"')
		two = i;
	if (one == -1 || two == -1)
		return (0);
	if ((index > one) && (index < two))
		return (1);
	return (0);
}

char	*built_err(char *res, char *s)
{
	int	flag;
	int	i;

	flag = doub_c(s, 1);
	flag += sing_c(s, 1);
	i = 1;
	if (flag > 0)
		while (s[i] && s[i] != ' ')
			i++;
	if (s[i] == ' ')
		while (s[i] == ' ' && s[i] != '"' && s[i] != '\'' && s[i])
			i++;
	flag = 0;
	flag += doub_c(s, i);
	flag += sing_c(s, i);
	if (s[i] != '"' && s[i] != '\'' && s[i] != '\0'
		&& flag != 0)
		res = "shid_pant";
	return (res);
}

int	q_count(char *s)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\'' || s[i] == '"')
			c++;
		i++;
	}
	return (c);
}

char	*dequote_built(char *s, char *tmp, t_norm *n)
{
	int		i;

	n->act = (char *)malloc(sizeof(char) * ft_strlen(s) + INLEN);
	i = 0;
	n->qcheck = 0;
	if (s[i] == '"')
		n->qcheck += doub_c(s, ++i);
	if (s[i] == '\'')
		n->qcheck += sing_c(s, ++i);
	n->j = 0;
	if (n->qcheck > 0)
		while (s[i] != '\'' && s[i] != '"' && s[i])
			n->act[n->j++] = s[i++];
	else
		return (s);
	if (s[i + 1] != '\0' && (s[i] == '"' || s[i] == '\''))
		i++;
	while (s[i] && s[i] != '"' && s[i] != '\'')
		n->act[n->j++] = s[i++];
	if (q_count(s) > 2)
		while (s[i])
			n->act[n->j++] = s[i++];
	n->act[n->j] = '\0';
	tmp = built_err(n->act, s);
	printf("%s", tmp);
	return (tmp);
}
