/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yosh_i.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:31:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/30 15:00:44 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YOSH_I_H
# define YOSH_I_H

# define INLEN 512
# define BUILTINCMD 0
# define SIMPLECMD 1
# define COMPLEXCMD 2

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <libgen.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_cmd
{
	char	***cmds;
	char	**tokens;
	char	**pipredir;
	int		end[2];
}	t_cmd;

extern char	**environ;

/// BUILTIN1_C ///
int		check_4_builtin(char **tokens);
int		echo(char **tokens);
int		cd(char **tokens);
int		pwd(void);
int		exports(char **tokens);

/// BUILTIN2_C ///
int		unset(char **tokens);
int		env(void);

/// ENV_C ///
char	*get_prog_path(char *prog_name);

/// EXPANDER_C ///

char	*expander(char *s);

/// FREE_C ///
void	free_2d(char **array);
void	free_3d(char ***array);

/// PARSE_C ///

int		parse_input(char *input, t_cmd *cmd);
char	**find_pipredir(char **tokens);
char	***cmd_list(char **tokens, char **pipredir);

/// REDIPIPE_C ///
void	action(char *act, int act_index, t_cmd *cmd);

/// RUN_C ///
void	run(int flag, t_cmd *cmd);
void	run_simplecmd(t_cmd *cmd);
void	run_cmplxfcker(t_cmd *cmd);

/// SETUP_C ///
void	init_yosh_i(void);
int		cmd_input(char *str);
void	print_prompt(void);

/// SIGNAL_C ///
void	sig_read_handle(void);
void	sig_text_handle(char *s);

#endif