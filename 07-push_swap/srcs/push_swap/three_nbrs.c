#include "push_swap.h"

void	ft_three_nbrs(t_all *all, t_stack *a)
{
	ft_find_minmax_a(all, a);

	printf("tre numeri. il massimo e' %d e il minimo e' %d\n", a->max, a->min);
	
}