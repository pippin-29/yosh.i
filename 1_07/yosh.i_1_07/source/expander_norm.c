/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 04:02:00 by tpawson           #+#    #+#             */
/*   Updated: 2023/11/28 09:55:29 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

char	*norm_act(char *act, char *cmp, char *s, int index)
{
	if (act)
		act = append_exist(cmp, s, index);
	if (act == NULL)
		act = append_init(cmp, s, index);
	return (act);
}
