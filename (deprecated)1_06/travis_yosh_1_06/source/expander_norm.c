/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 04:02:00 by tpawson           #+#    #+#             */
/*   Updated: 2023/11/20 04:16:01 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

char	*norm_act(char *act, char *cmp, char *s, int index)
{
	int	i;

	i = index;
	if (act)
		act = append_exist(cmp, s, index);
	if (act == NULL)
		act = append_init(cmp, s, index);
	return (act);
}
