/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:52:19 by tpawson           #+#    #+#             */
/*   Updated: 2023/12/04 11:44:04 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

char	*norm_save(char *s, int tmp_i)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	i = 0;
	while (s[tmp_i] && s[tmp_i] != ':')
		tmp_i++;
	while (s[tmp_i] && s[tmp_i] != ' ')
		tmp[i++] = s[tmp_i++];
	tmp[i] = '\0';
	return (tmp);
}

char	*append_init(char *cmp, char *s, int index)
{
	int		i;
	int		tmp_i;
	char	*tmp;
	char	*res;

	i = 0;
	tmp_i = index;
	tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	res = tmp;
	if (s[index - 1] == '=')
	{
		while (s[index] && s[index] != ' ' && index != 0)
			index--;
		while (s[index] && s[index] != '=')
			tmp[i++] = s[index++];
		tmp[i] = '\0';
		if (ft_strcmp(tmp, cmp))
			res = norm_save(s, tmp_i);
		return (res);
	}
	return (NULL);
}

char	*append_exist(char *cmp, char *s, int index, t_cmd *cmd)
{
	char	*res;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	res = (char *)malloc(sizeof(char) * ft_strlen(s) * INLEN);
	while (s[index] && s[index] != ':')
		index++;
	tmp = retrv_envv(cmp, cmd);
	if (s[index] == ':')
	{
		while (tmp[j])
			res[i++] = tmp[j++];
		while (s[index])
			res[i++] = s[index++];
		res[i] = '\0';
		return (res);
	}
	return (tmp);
}

char	*new_str(char *s, int index, char *cmp, t_cmd *c)
{
	int		i;
	char	*res;

	c->n->j = 0;
	i = -1;
	c->n->act = retrv_envv(cmp, c);
	c->n->s_flag = sing_c(s, index);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s) + (INLEN * INLEN)));
	while (++i != index)
		res[i] = s[i];
	c->n->tmp = c->n->act;
	c->n->act = norm_act(cmp, s, index, c);
	if (c->n->act && c->n->s_flag == 0)
		while (c->n->act[c->n->j])
			res[i++] = c->n->act[c->n->j++];
	else if (c->n->s_flag == 1)
		while (s[index] && s[index] != '/' && s[index] != ' ')
			res[i++] = s[index++];
	while (s[index] && s[index] != '/' && s[index] != ' '
		&& s[index] != '"' && s[index] != '\'')
		index++;
	while (s[index])
		res[i++] = s[index++];
	res[i] = '\0';
	return (res);
}

char	*expander(char *s, t_cmd *cmd)
{
	char	*cmp;
	char	*tmp;
	int		i;
	int		index;
	int		j;

	i = -1;
	index = 0;
	while (s[++i])
	{
		if (s[i] == '$')
		{
			cmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
			j = 0;
			index = i++;
			while (s[i] != '\0' && s[i] != ' ' && s[i] != '/' && s[i] != ':'
				&& s[i] != '"' && s[i] != '\'')
				cmp[j++] = s[i++];
			cmp[j] = '\0';
			tmp = new_str(s, index, cmp, cmd);
			s = tmp;
			free(cmp);
		}
	}
	return (s);
}
