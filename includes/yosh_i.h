/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yosh_i.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 10:31:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/08/17 11:15:41 by dhadding         ###   ########.fr       */
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

typedef struct s_cmd
{
	char ***cmds;
	char *pipredir;

} t_cmd;

// /// BUILTIN1_C ///
// int		check_4_builtin(char **tokens);
// int		echo(char *option, char **strings);
// int		cd(char *path);
// int		pwd(void);
// int		export(char *var);

// /// BUILTIN2_C ///
// int		unset(char *var);
// int		env(void);
// int		exit_shell(void);

/// CMD_C ///
void	run(int flag, t_cmd *cmd);
void	run_simplecmd(t_cmd *cmd);

/// PARSE_C ///
int		parse_input(char *input, t_cmd *cmd);
char	*find_piperedir(char **tokens);

/// SETUP_C ///
void	init_yosh_i();
int		cmd_input(char *str);
void	print_prompt();

# endif