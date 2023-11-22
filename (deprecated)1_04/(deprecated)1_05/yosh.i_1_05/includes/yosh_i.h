/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yosh_i.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:31:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/11/15 14:58:31 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YOSH_I_H
# define YOSH_I_H

# define INLEN 1024
# define BUILTINCMD 0
# define SIMPLECMD 1
# define COMPLEXCMD 2
# define HISTORY_PATH ".yosh_history"

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
	char	input[INLEN];
	int		flag;
	char	*expanded;
	char	**cmd;
	char	**tokens;
	char	**pipredir;
	int		estatus;
	int		hack;
}	t_cmd;

typedef struct s_ops
{
	int		fd_in;
	int		fd_out;
	int		fd_in_red;
	int		fd_out_red;
	int		pipe[2];
	pid_t	pid;
	char	*here_prompt;
	char	*here_EOF;
	int		fd_here;
}	t_ops;

typedef struct s_prompt
{
	char	*prompt;
	char	*username;
	char	hostname[128];
	char	cwd[1024];
	char	*exitstatus;
	char	*out;
	char	*green;
	char	*cyan;
	char	*red;
	char	*white;
}	t_prompt;

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
int		continue_w_error(char **tokens);

/// CMD-OPS_C ///
void	run_complexcmd(t_cmd *cmd);
void	runf(t_cmd *cmd);
int		count_2_pipredir(char **tokens, char *op);
char	**cmd_group(char **token_group, char *op);
int		count_group(char **token_group, char *op);
int		is_op(char *token, char *op);
void 	in_here(t_cmd *cmd, t_ops *ops);
void	out(t_cmd *cmd, t_ops *ops);
int		write_2_fd_here(t_ops *ops);
int		check_if_program_2_run(char *op, char *cmd_alpha);

/// ENV_C ///
char	*get_prog_path(char *prog_name);
int		path_attached(char *prog_name);
char	*retrv_envv(char *envvar);
char	*env_grab_value(char *environitem, int len);

/// EXPANDER_C ///
char	*append_init(char *cmp, char *s, int index);
char	*append_exist(char *cmp, char *s, int index);
char	*new_str(char *s, int index, char *cmp);
char	*expander(char *s);

/// FREE_C ///
void	free_2d_char(char **array);

/// HISTORY_C ///
void	load_history(void);
void	save_history(void);

/// PARSE_C ///
int		parse_input(t_cmd *cmd);
void	find_pipes_redirection(t_cmd *cmd);

/// PRINT_C ///
void	print_list_2d(char **list);
void	print_int_list(int *list, int count);

/// PROMPT_C ///
void	set_prompt(t_cmd *cmd, t_prompt *prompt);
void	store_prompt(t_prompt *prompt);

/// RUN_C ///
void	run(t_cmd *cmd);
void	run_simplecmd(t_cmd *cmd);

/// SETUP_C ///
void	entry_message(void);
int		cmd_input(t_cmd *cmd, t_prompt *prompt);

/// SIGNAL_C ///
void	sig_ctrlc(int sig);
void	sig_read_handle(void);
void	sig_doc_handle(void);
#endif