/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yosh_i.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:31:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/16 12:56:26 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YOSH_I_H
# define YOSH_I_H

# define INLEN 512

# include "../libft/includes/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <libgen.h>
# include <string.h>


/// SETUP_C ///
void	init_yosh_i();
int		cmd_input(char *str);
void	print_prompt();

# endif