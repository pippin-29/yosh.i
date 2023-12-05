/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yosh_i.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:31:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/04 15:07:49 by dhadding         ###   ########.fr       */
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

typedef struct s_norm
{
	char	*act;
	char	*tmp;
	// char	**environ;
	int		s_flag;
	int		j;
	int		i;
	int		qcheck;
	size_t	ii;
	size_t	jj;
	size_t	k;
}	t_norm;

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

typedef struct s_cmd
{
	char		input[INLEN];
	int			flag;
	char		*expanded;
	char		**environ;
	char		**cmd;
	char		**tokens;
	char		**pipredir;
	int			estatus;
	int			fd_stdin;
	int			fd_stdout;
	int			fd_infile;
	int			fd_outfile;
	char		*here_prompt;
	char		*here_buffer;
	char		*here_eof;
	int			fd_here;
	int			rl_yn;
	int			pipe_c;
	int			no_command;
	int			fd_to_pipe;
	int			fd_from_pipe;
	int			pump;
	int			run;
	int			io_dup_out;
	int			io_dup_in;
	int			io_cross_out;
	int			io_cross_in;
	char		*yosh_history;
	char		*to_pipe;
	char		*temporary_heredoc;
	char		*exitstatuskey;
	char		*home;
	t_norm		*n;
	t_prompt	*prompt;
}	t_cmd;

/// BUILTIN1_C ///
int		run_builtin(t_cmd *cmd, t_norm *norm);
int		echo(t_cmd *cmd);
int		cd(t_cmd *cmd);
int		pwd(void);

/// BUILTIN2_C ///
int		unset(t_cmd *cmd);
void	exitshell(t_cmd *cmd, t_norm *norm);
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
int		contract_env(int index, t_cmd *cmd);
int		add_envv(char *envvar, t_cmd *cmd);
int		error_check_add_envv(char *envvar);
int		update_envv(char *envvar, t_cmd *cmd);

/// ENV3_C ///
int		envvar_len(char *envvar);
int		envv_naming_check(char *envvar);
void	set_envvars(t_cmd *cmd);

/// EXPANDER_NORM_C ///
char	*norm_act(char *cmp, char *s, int index, t_cmd *c);

/// EXPANDER_C ///
char	*append_init(char *cmp, char *s, int index);
char	*append_exist(char *cmp, char *s, int index, t_cmd *c);
char	*new_str(char *s, int index, char *cmp, t_cmd *c);
char	*expander(char *s, t_cmd *cmd);

/// FILE_C ///
int		is_valid_filename(char *input);
void	close_files(t_cmd *cmd);

/// FREE_C ///
void	free_2d_char(char **array);
void	free_cmd_help(t_cmd *cmd);
void	free_cmd(t_cmd *cmd);
void	free_prompt(t_prompt *prompt);
void	free_norm(t_norm *norm);

/// HISTORY_C ///
void	load_history(t_cmd *cmd);
void	save_history(t_cmd *cmd);

/// IO_C ///
int		in(t_cmd *cmd, int i);
int		in_here(t_cmd *cmd, int i, t_norm *norm);
void	write_2_fd_here(t_cmd *cmd, t_norm *norm);
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
void	set_prompt(t_cmd *cmd);
void	store_prompt(t_prompt *prompt);

/// QUOTES_C ///
int		sing_c(char *s, int index);
int		doub_c(char *s, int index);
char	*dequote_built(char *s, char *tmp, t_norm *norm);

/// QUOTES2_C ///
char	*dequote_str(char *s);
char	*strndup_no_quotes(char *s, size_t n);
char	**ft_mini_split(char *s, char c, t_norm *n);

/// REDIRECTION_C ///
int		redirection(t_cmd *cmd, int i, t_norm *norm);
void	reset_io(t_cmd *cmd);
int		count_pipes(t_cmd *cmd);

/// RUN_C ///
void	run(t_cmd *cmd, t_norm *norm);
void	runr(t_cmd *cmd);
void	run_simplecmd(t_cmd *cmd);
void	run_complexcmd(t_cmd *cmd, t_norm *norm);

/// SETUP_C ///
void	entry_message(void);
int		cmd_input(t_cmd *cmd, t_norm *norm);
int		check_4_semi_bslash(char *check);

/// SIGNAL_C ///
void	sig_ctrlc(int sig);
void	sig_read_handle(t_cmd *cmd);
void	sig_sugma(int sig, siginfo_t *info, void *context);
void	sig_ctrls(int sig);
void	handler(int sig, siginfo_t *info, void *context);

#endif