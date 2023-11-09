/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redipipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpawson < tpawson@student.42adel.org.au    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:04:37 by travis            #+#    #+#             */
/*   Updated: 2023/11/03 07:19:26 by tpawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/yosh_i.h"
/*
void    action(char *act, int act_index, t_cmd *cmd)
{
    char    *path_1;
    char    *path_2;
    int     fd[2];

    path_1 = (char *)malloc(sizeof(char));
    path_2 = (char *)malloc(sizeof(char));

    path_1 = get_pre(act_index, cmd, act);
    path_2 = get_suf(act_index, cmd, act);
    if (strcmp(act, ">") || strcmp(act, ">>"))
        output_re(act, path_1, path_2, fd);
    if (strcmp(act, "<"))
        input_re(path_1, path_2, fd);
    if (strcmp(act, "<<"))
        printf("err, cannot append input to program");
    if (strcmp(act, "|"))
        ft_pipe(path_1, path_2, fd);
}
//get it to work like project only with multiple pipes
void    ft_pipe(char *path_1, char *path_2, int *fd)
{
    pid_t pid;
    pid = fork();
    if (pid == -1 || pipe(fd) < 0)
        perror("Fork or Pipe Failure: ");
    if (pid == 0)
        ft_child(path_1, environ, fd);
    ft_par(path_2, environ, fd);
}
//look at behave
void    output_re(char *act, char *path_1, char *path_2, int *fd)
{
    int res_fd;
    if (strcmp(act,">"))
    {
        res_fd = open(path_2, O_WRONLY | O_CREAT | O_TRUNC);
        if (res_fd == -1)
            return ;
        write (fd[1], path_1, ft_strlen(path_1));
    }    
    else if (strcmp(act,">>"))
    {
        res_fd = open(path_2, O_WRONLY | O_CREAT | O_APPEND);
        if (res_fd == -1)
            return ;
        write (fd[1], path_1, ft_strlen(path_1));
    }
}
// look at behave
void    input_re(char *path_1, char *path_2, int *fd)
{
    int res_fd;
    res_fd = open(path_1, O_RDONLY);
    if (res_fd == -1)
        return ;
    write(fd[0], path_2, ft_strlen(path_2));
}
*/