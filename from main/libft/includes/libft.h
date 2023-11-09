/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <daniel42.c@engineer.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 12:40:00 by dhadding          #+#    #+#             */
/*   Updated: 2023/05/24 20:32:43 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

// OPEN_MAX is a reasonable limit to the number of files which
// can be open at one time.

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

/* Part 1 Functions */
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, unsigned long int len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);

void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s, size_t n);

/* Additional Functions */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_lstlen(char **list);
char	**ft_tabcpy(char **in, char **out);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* Bonus Functions */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* GET_NEXT_LINE */
char	*get_next_line(int fd);

/* FT_PRINTF */

int		ft_printf(const char *format, ...);

int		ft_printf_print_char(int c);
int		ft_printf_print_int(int n);
int		ft_printf_print_u_int(unsigned int u);
int		ft_printf_print_str(char *s);
int		ft_printf_print_hex(unsigned int x, char format);
int		ft_printf_print_pointer(unsigned long long p);
int		ft_printf_print_pcent(void);

void	ft_put_str(char *str);
void	ft_put_ptr(uintptr_t num);
int		ft_ptr_len(uintptr_t num);
int		ft_hex_length(unsigned int num);
void	ft_put_hex(unsigned int num, char format);
size_t	ft_num_len(int n);
size_t	ft_unsigned_num_len(unsigned int num);
char	*ft_uitoa(unsigned int n);

#endif