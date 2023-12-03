/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yosh_i.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:31:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/03 13:38:42 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YOSH_I_H
# define YOSH_I_H

# define INLEN 1024
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
# include "yosh_macros.h"

typedef struct s_cmd
{
	char	input[INLEN];
	int		flag;
	char	*expanded;
	char	**environ;
	char	**cmd;
	char	**tokens;
	char	**pipredir;
	int		estatus;
	int		fd_stdin;
	int		fd_stdout;
	int		fd_infile;
	int		fd_outfile;
	char	*here_prompt;
	char	*here_buffer;
	char	*here_eof;
	int		fd_here;
	int		rl_yn;
	int		pipe_c;
	int		no_command;
	int		fd_to_pipe;
	int		fd_from_pipe;
	int		pump;
	int		run;
	int		io_dup_out;
	int		io_dup_in;
	int		io_cross_out;
	int		io_cross_in;
}	t_cmd;

typedef struct s_prompt
{
	char	*prompt;
	char	*username;
	char	hostname[128];
	char	*cwd;
	char	*exitstatus;
	char	*out;
	char	*green;
	char	*cyan;
	char	*red;
	char	*white;
}	t_prompt;

typedef struct s_norm
{
	char	*act;
	char	*tmp;
	int		s_flag;
	int		j;
	int		i;
	int		qcheck;
}	t_norm;

/// BUILTIN1_C ///
int		run_builtin(t_cmd *cmd);
int		echo(t_cmd *cmd);
int		cd(t_cmd *cmd);
int		pwd(void);

/// BUILTIN2_C ///
int		unset(t_cmd *cmd);
void	exitshell(t_cmd *cmd);
int		env(t_cmd *cmd);
void	cd_empty(t_cmd *cmd);
int		exports(t_cmd *cmd);

/// ENV_C ///
char	*get_prog_path(char *prog_name, t_cmd *cmd);
int		path_attached(char *prog_name);
char	*retrv_envv(char *envvar, t_cmd *cmd);
char	*env_grab_value(char *environitem, int len);
void	copy_environ(char **envp, t_cmd *cmd);

/// ENV2_C ///
int		rm_envv(char *envvar, t_cmd *cmd);
int		contract_env(char **tda, int index, t_cmd *cmd);
int		add_envv(char *envvar, t_cmd *cmd);
int		error_check_add_envv(char *envvar);
int		update_envv(char *envvar, t_cmd *cmd);

/// ENV3_C ///
int		envvar_len(char *envvar);
int		envv_naming_check(char *envvar);
void	set_envvars(t_cmd *cmd);

/// EXPANDER_NORM_C ///
char	*norm_act(char *act, char *cmp, char *s, int index, t_cmd *cmd);

/// EXPANDER_C ///
char	*append_init(char *cmp, char *s, int index);
char	*append_exist(char *cmp, char *s, int index, t_cmd *cmd);
char	*new_str(char *s, int index, char *cmp, t_norm *norm, t_cmd *cmd);
char	*expander(char *s, t_norm *norm, t_cmd *cmd);

/// FILE_C ///
int		is_valid_filename(char *input);

/// FREE_C ///
void	free_2d_char(char **array);

/// HISTORY_C ///
void	load_history(t_cmd *cmd);
void	save_history(t_cmd *cmd);

/// IO_C ///
int		in(t_cmd *cmd, int i);
int		in_here(t_cmd *cmd, int i);
void	write_2_fd_here(t_cmd *cmd);
int		out(t_cmd *cmd, int i);
int		out_append(t_cmd *cmd, int i);

/// OP_C //
int		find_op(char **tokens);
int		check_4_command(char *cmd_alpha, t_cmd *cmd);
int		is_prog_on_path(char *prog_name, t_cmd *cmd);
int		last_command(t_cmd *cmd, int i);

/// PARSE_C ///
int		parse_input(t_cmd *cmd, t_norm *norm);
void	find_pipes_redirection(t_cmd *cmd);
char	**cmd_group(char **token_group, int end);

/// PIPE-IO_C ///
int		pipe_next(char **tokens);
int		out_command(t_cmd *cmd);
int		in_command(t_cmd *cmd);

/// PRINT_C ///
void	print_list_2d(char **list);

/// PROMPT_C ///
void	set_prompt(t_cmd *cmd, t_prompt *prompt);
void	store_prompt(t_prompt *prompt);

/// QUOTES_C ///
int		sing_c(char *s, int index);
int		doub_c(char *s, int index);
char	*dequote_built(char *s, char *tmp, t_norm *norm);

/// QUOTES2_C ///
char	*dequote_str(char *s);

/// REDIRECTION_C ///
int		redirection(t_cmd *cmd, int i);
void	reset_io(t_cmd *cmd);
int		count_pipes(t_cmd *cmd);

/// RUN_C ///
void	run(t_cmd *cmd);
void	runr(t_cmd *cmd);
void	run_simplecmd(t_cmd *cmd);
void	run_complexcmd(t_cmd *cmd);

/// SETUP_C ///
void	entry_message(void);
int		cmd_input(t_cmd *cmd, t_prompt *prompt);
int		check_4_semi_bslash(char *check);

/// SIGNAL_C ///
void	sig_ctrlc(int sig);
void	sig_read_handle(t_cmd *cmd);
void	sig_sugma(int sig, siginfo_t *info, void *context);
void	sig_ctrls(int sig);
void	handler(int sig, siginfo_t *info, void *context);

#endif