/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 04:02:00 by tpawson           #+#    #+#             */
/*   Updated: 2023/12/03 16:04:18 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

char	*norm_act(char *cmp, char *s, int index, t_cmd *c)
{
	if (c->n->act)
		c->n->act = append_exist(cmp, s, index, c);
	if (c->n->act == NULL)
		c->n->act = append_init(cmp, s, index);
	return (c->n->act);
}
