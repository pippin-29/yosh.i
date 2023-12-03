/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:07:31 by tpawson           #+#    #+#             */
/*   Updated: 2023/12/03 14:43:43 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

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

static size_t	ft_wordcnt(char const *s, char c)
{
	size_t	word_count;
	size_t	trigger;
	int		f;
	int		i;

	trigger = 0;
	word_count = 0;
	i = 0;
	while (s[i])
	{
		f = 0;
		f += doub_c((char *)s, i);
		f += sing_c((char *)s, i);
		if (s[i] != c && trigger == 0)
		{
			trigger = 1;
			word_count++;
		}
		else if (s[i] == c && f == 0)
			trigger = 0;
		i++;
	}
	return (word_count);
}

char	*strndup_no_quotes(const char *s, size_t n)
{
	char	*out;
	size_t	i;
	size_t	j;

	out = malloc(n + 1);
	if (!out)
		return (0);
	i = 0;
	j = 0;
	while (j < n && s[i])
	{
		while (s[i] == '\'' || s[i] == '"')
			i++;
		out[j++] = s[i++];
	}
	while (j <= n)
		out[j++] = 0;
	return (out);
}

char	**ft_mini_split(char const *s, char c, t_norm *n)
{
	char	**split;
	int		f;

	n->k = ft_wordcnt(s, c);
	split = malloc(sizeof(char *) * (n->k + 1));
	n->ii = 0;
	n->jj = 0;
	while (n->ii < n->k)
	{
		while (s[n->jj] == c)
			n->jj++;
		s = &s[n->jj];
		n->jj = 0;
		while (s[n->jj++])
		{
			f = 0;
			f += doub_c((char *)s, (int)n->jj);
			f += sing_c((char *)s, (int)n->jj);
			if (s[n->jj] == c && f == 0)
				break ;
		}
		split[n->ii++] = strndup_no_quotes(s, n->jj);
	}
	split[n->ii] = 0;
	return (split);
}
