/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yosh_i.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:31:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/10 09:45:07 by dhadding         ###   ########.fr       */
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
# include <errno.h>
# include <stdbool.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_cmd
{
	char	***cmds;
	char	**tokens;
	char	**pipredir;

}	t_cmd;

typedef struct s_prompt
{
	char	*prompt;
	char	*username;
	char	hostname[128];
	char	cwd[1024];
	char	*exitstatus;
	char	*out;
	char 	*green;
	char	*cyan;
	char	*red;
	char	*white;
}	t_prompt;

extern char	**environ;
int 		g_estatus;

/// BUILTIN1_C ///
int		check_4_builtin(char **tokens);
int		echo(char **tokens);
int		cd(char **tokens);
int		pwd(void);
int		exports(char **tokens);

/// BUILTIN2_C ///
int		unset(char **tokens);
int		env(void);
int		continue_w_error(char **tokens);

/// ENV_C ///
char	*get_prog_path(char *prog_name);
int		path_attached(char *prog_name);
char	*retrv_envv(char *envvar);
char	*env_grab_value(char *environitem, int len);

/// EXPANDER_C ///
char    *append_init(char *cmp, char *s, int index);
char	*append_exist(char *cmp, char *s, int index);
char    *new_str(char *s, int index, char *cmp);
char	*expander(char *s);

/// FREE_C ///
void	free_2d_char(char **array);
void	free_3d_char(char ***array);

/// PARSE_C ///
int		parse_input(char *input, t_cmd *cmd);
char	**find_pipredir(char **tokens);

/// PRINT_C ///
void 	print_list_2d(char **list);
void 	print_int_list(int *list, int count);

/// PROMPT_C ///
void	set_prompt(t_prompt *prompt);
void	store_prompt(t_prompt *prompt);

/// RUN_C ///
void	run(int flag, t_cmd *cmd);
void	run_simplecmd(t_cmd *cmd);

/// SETUP_C ///
void	entry_message(void);
int		cmd_input(char *str, t_prompt *prompt);

/// SIGNAL_C ///
void	sig_ctrlc(int sig);
void	sig_read_handle(void);
void	sig_text_handle(char *s);

#endif