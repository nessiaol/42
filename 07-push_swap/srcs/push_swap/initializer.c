#include "push_swap.h"

void	ft_init(t_all *all)
{
	all->moves = 0;
	all->size = 0;
}

void	ft_find_minmax_a(t_all *all, t_stack *a)
{
	int	i;
	t_stack	temp;
	i = 0;

	temp.nbrs = (int *)calloc(sizeof(int *), all->size-1);
	while (a->nbrs[i])
	{
		temp.nbrs[i] = a->nbrs[i];
		i++;
	}
	ft_bubblesort(all, &temp);
	a->max = temp.nbrs[all->size-1];
	a->min = temp.nbrs[0];

	free(temp.nbrs);
	printf("massimo a: %d\n", a->max);
	printf("minimo a:  %d\n", a->min);
}

// void	ft_find_minmax_b(t_all *all, t_stack *b)
// {
// 	int i;

// 	i = 0;
// 	b->max = b->nbrs[i];
// 	b->min = b->nbrs[i];
// 	while(i < all->size)
// 	{
// 		if (b->nbrs[i] > b->max)
// 			b->max = b->nbrs[i];
// 		i++;
// 	}
// 	i = 0;
// 	while(i >= 0)
// 	{
// 		if (b->nbrs[i] > b->min)
// 			b->min = b->nbrs[i];
// 		i++;
// 	}

// 	printf("massimo b: %d", b->max);
// 	printf("minimo b:  %d", b->min);
// }