/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 12:31:14 by cserapon          #+#    #+#             */
/*   Updated: 2021/10/07 13:35:44 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Includes
*/

# include <stdlib.h>

/*
** Prototypes
*/

/*
** Characters
*/

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isspace(int c);
int		ft_isprint(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/*
** Strings
*/

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_jump_spaces(char *line, int *i);
void	ft_jump_quotes_text(char *line, int *i, int dquote);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
int		ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strcmp_until_inc(const char *s1, const char *s2, int c);
int		ft_strcmp_until_exc(const char *s1, const char *s2, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_isescaped(char *line, int i);
int		ft_isdigit_string(char *s);
int		ft_isspace_string(const char *s);
void	ft_strcpy(char *dst, char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strcharjoin(char *old, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strtrim(const char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *haystack, const char *needle,
			size_t len);
char	*ft_strinsubs(const char *body, const char *to_insert,
			int subslen, int in_pos);
char	**ft_split(char *str, char *charset);
char	**ft_bnessi_split(char const *s, char c);
char	**ft_split_bash(char *line);
int		ft_count_strs_bash(char *line, char *changes, int len, int i);
char	*ft_separate_strs_bash(char *line, char *escapes, char **changes,
			int in_quote);
int		ft_case_3_check(char *changes, int *i, int len);
int		ft_case_2_check(char *changes, int *i, int len);
int		ft_case_1_check(char *changes, int *i, int len);
void	ft_case_2(char ***splitted, char *line, int *i);
void	ft_case_1(char ***splitted, char *line, int *i);

/*
** Matrixes
*/

int		ft_mtxlen(char **m);
void	ft_if_free_mtx(char ***matrix);
char	**ft_mtxcpy(char **m);
void	ft_mtxprint(char **m);

/*
** Integers
*/

char	*ft_itoa(int n);
void	ft_swap(int *x, int *y);
double	ft_dist(double x1, double y1, double x2, double y2);

/*
** Tabs
*/

void	ft_tabcpy(int *dst, int *src, int size);

/*
** Voids
*/

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

/*
** Allocation
*/

void	*ft_calloc(size_t count, size_t size);
void	ft_if_free(void **freeable);

/*
** Ft_fprintf
*/

int		ft_fprintf(int fd, const char *format, ...);

#endif
