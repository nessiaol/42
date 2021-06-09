
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

# define BUFF_SIZE 3
# define FD_MAX 1024

/*libft1.c*/
size_t	ft_strlen(const char *str);
char	*ft_strnew(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_strdel(char **as);
char	*ft_strdup(const char *src);

/*libft2.c*/
char	**ft_strsplit(char const *s, char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
int		ft_strequ(char const *s1, char const *s2);
char	*ft_strchr(const char *s1, int s2);

/*libft3.c*/
int		ft_wordcount(const char *s, char c);
void	ft_putendl(char const *str);
int		get_next_line(const int fd, char **line);

/*libft4.c*/
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *s1, const char *s2);
size_t	ft_wordlen(const char *str, char c);

/*ops.c*/
void	s(int *a, int *b, char *str, int *n);
int		pb(int *a, int *b, int *n);
int		pa(int *a, int *b, char *str, int *n);
void	rr(int *a, int *b, char *str, int *n);
void	r(int *a, int *b, char *str, int *n);

/*check.c*/
int		checka(int *a, int n);
int		checkb(int *b, int n);

/*error_add.c*/
void	dub_check(int ac, int *num);
void	place1(int *x, int *a, char **av);
void	place2(int *n, int *a, char **av);
void	erpl2(int *a, int *x, char **tmp);
void	erpl1(int *a, int *x, char **tmp);

/*num_add.c*/
void	pb_asort(int *a, int *b, int *n);
void	passb(int *a, int *b, int *n);
void	ex(int *min, int *max, int *i);
void	add_erpl2(char *av, int *a, int *x);

/*sort_3_num.c*/
void	ft_upto_three(int *a, int *b, int *n);
void	ft_upto_three_b(int *a, int *b, int *n);

/*sort_6_num*/
int		mid(int *a, int n);
void	ft_upto_six(int *a, int *b, int *n);

/*sort_x.c*/
void	ft_oversix(int *a, int *b, int *n);

#endif
