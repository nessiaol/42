#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#include "utils.h"
//#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>


typedef struct	s_stack
{
	int 	min;
	int		max;
	int		*nbrs;
	int		size;
}			t_stack;

typedef struct s_all
{
	int		size;
	int		moves;
	t_stack	a;
	t_stack	b;
}			t_all;

int main();
void	ft_print_stack(t_all *all, t_stack *a);
int		ft_count_numbers(char const *s, char c);
void    ft_init_stack(char **argv, t_all *all);


void	ft_init(t_all *stack);

void 	ft_swap(int *a, int *b);
void ft_bubblesort(t_all *all, t_stack *a);

void	ft_rotate(t_all *all, t_stack *a);
void	ft_rotate_rev(t_all *all, t_stack *a);

void	ft_read_argvs(int argc, char **argv, t_all *all);
int		ft_new_atoi(const char *str);
int		ft_numlen(int n);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);




//----
void	ft_swap_s(t_all *stack, int i, int j);

#endif