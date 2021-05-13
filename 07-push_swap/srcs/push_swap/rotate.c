#include "push_swap.h"

void	ft_rotate(t_all *all, t_stack *a)
{
	int y;
	int temp;

	//stack->size = 6;
	y = 0;
	temp = a->nbrs[y];
	while (y < all->size)
	{
		a->nbrs[y] = a->nbrs[y+1];
		y++;
	}
	a->nbrs[y] = temp;
	//printf("ra\n");
	all->moves++;
}

void	ft_rotate_rev(t_all *all, t_stack *a)
{
	int y;
	int temp;

	//all->size = 6;
	y = all->size;
	temp = a->nbrs[y];
	while (y > 0)
	{
		a->nbrs[y] = a->nbrs[y-1];
		y--;
	}
	a->nbrs[y] = temp;
	//printf("ra\n");
	all->moves++;
}