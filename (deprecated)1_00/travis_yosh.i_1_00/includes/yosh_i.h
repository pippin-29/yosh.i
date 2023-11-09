/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yosh_i.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:31:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/10/13 15:47:41 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YOSH_I_H
# define YOSH_I_H

# define INLEN 512
# define BUILTINCMD 0
# define SIMPLECMD 1
# define COMPLEXCMD 2

# include "../libft/includes/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <libgen.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <signal.h>

typedef struct s_cmd
{
	char	***cmds;
	char	**tokens;
	char	*pipredir;
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

/// SIGNAL_C ///

void	sig_ctrlc(int sig);
void	sig_ctrld(int sig);

/// ENV_C ///
char	*get_prog_path(char *prog_name);

/// FREE_C ///
void	free_2d(char **array);
void	free_3d(char ***array);

/// PARSE_C ///
int		parse_input(char *input, t_cmd *cmd);
char	*find_piperedir(char **tokens);
char	***cmd_list(char **tokens, char *pipredir);

/// RUN1_C ///
void	run(int flag, t_cmd *cmd);
// void	run_complexcmd(t_cmd *cmd, int a, int trigger);
void	run_simplecmd(t_cmd *cmd);

/// RUN2_C ///
// void	run_pipe(t_cmd *cmd, int a, int trigger);
// void	run_redir_from_file(t_cmd *cmd, int a, int trigger);
// void	run_redir_to_file(t_cmd *cmd, int a, int trigger);
// void	run_redir_to_file_append(t_cmd *cmd, int a);
// void	run_redir_from_file_find(t_cmd *cmd, int a);

/// SETUP_C ///
void	init_yosh_i(void);
int		cmd_input(char *str);
void	print_prompt(void);
void	sig_read_handle(void);

#endif
