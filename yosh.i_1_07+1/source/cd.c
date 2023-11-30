/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:29:50 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/30 14:25:22 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"

void	cd_empty(void)
{
	if (chdir(retrv_envv("HOME")) == 0)
	{
		add_envv(ft_strjoin("OLDPWD=", retrv_envv("PWD")));
		add_envv(ft_strjoin("PWD=", retrv_envv("HOME")));
	}
}
