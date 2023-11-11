/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:52:19 by tpawson           #+#    #+#             */
/*   Updated: 2023/11/06 10:24:45 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

char    *new_str(char *s, int index, char *cmp)
{
    int i;
    int j;
    char *res;
    char *act;

    i = -1;
    j = 0;
    act = getenv(cmp);
    if (!act)
        return (NULL);
    res = (char *)malloc(sizeof(char) * (ft_strlen(s) + ft_strlen(act) + 1));
    while(++i != index)
        res[i] = s[i];
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