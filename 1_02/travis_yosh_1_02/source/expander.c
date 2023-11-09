/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:52:19 by tpawson           #+#    #+#             */
/*   Updated: 2023/11/09 16:18:28 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

char    *append_init(char *cmp, char *s, int index)
{
    int i;
	int	tmp_i;
    char *tmp;
	char *res;

    i = 0;
	tmp_i = index;
    tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	res = tmp;
    if (s[index - 1] == '=')
    {
        while (s[index] && s[index] != ' ')
            index--;
        while (s[index] && s[index] != '=')
            tmp[i++] = s[index++];
		tmp[i] = '\0';
        if (strcmp(tmp, cmp))
        {
			i = 0;
			while (s[tmp_i] && s[tmp_i] != ':')
				tmp_i++;
			while (s[tmp_i] && s[tmp_i] != ' ')
				res[i++] = s[tmp_i++];
			res[i] = '\0';
		}
		return (res);
	}
	return (NULL);
}

char	*append_exist(char *cmp, char *s, int index)
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
	tmp = getenv(cmp);
	if (s[index] == ':')
	{
		while (s[index])
			res[i++] = s[index++];
		while(tmp[j])
			res[i++] = tmp[j++];
		res[i] = '\0';
		return (res);
	}
	return (tmp);
}

char    *new_str(char *s, int index, char *cmp)
{
    int i;
    int j;
    char *res;
    char *act;

    i = -1;
    j = 0;
    act = getenv(cmp);
    res = (char *)malloc(sizeof(char) * (ft_strlen(s) + (INLEN * INLEN)));
    while(++i != index)
        res[i] = s[i];
	if (act)
		act = append_exist(cmp, s, index);
    if (act == NULL)
        act = append_init(cmp, s, index);
	if (act)
		while(act[j])
            res[i++] = act[j++];
    while(s[index] && s[index] != '/' && s[index] != ' ')
        index++;
    while (s[index])
        res[i++] = s[index++];
    res[i] = '\0';
    return (res);
}

char    *expander(char *s)
{
    char *cmp;
    char *tmp;
    int i;
    int index;
    int j;

    i = -1;
    index = 0;
    cmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);    
    while (s[++i])
    {
        if (s[i] == '$')
        {
            cmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
            j = 0;
            index = i++;
            while(s[i] != '\0' && s[i] != ' ' && s[i] != '/' && s[i] != ':')
                cmp[j++] = s[i++];
            cmp[j] = '\0';
            tmp = new_str(s, index, cmp);
            s = tmp;
            free(cmp);
        }
    }
    return (s);
}