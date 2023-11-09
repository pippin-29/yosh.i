/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:18:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/09 15:23:22 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	while (*s || ((*s == '\0') && ((char)c == '\0')))
	{
		if (((char) *s) == ((char)c))
			return ((char *)s);
		s++;
	}
	return (0);
}
 