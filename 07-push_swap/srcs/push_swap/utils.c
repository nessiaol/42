#include "push_swap.h"

int		ft_checkquotes(char *argument)
{
	int n;

	n = 0;
	while (argument[n])
	{
		if (argument[0] == '-')
        	n++;
		if (!ft_isdigit(argument[n]))
			return(1);
		n++;
	}
	return(0);
}

void	ft_strategy(t_all *all, t_stack *a)
{
	int x;

	x = 0;
	if (all->size == 2)
	{
		if (a->nbrs[0] > a->nbrs[1])
		{
			ft_swap(&a->nbrs[0], &a->nbrs[1]);
			all->moves++;
		}
	}
	if (all->size == 3)
		ft_three_nbrs(all, a);
	// if (all->size <= 5)
	// 	ft_five_nbrs(all, a);
	// if (all->size <= 100)
	// 	ft_hundred_nbrs(all, a);
	// if (all->size > 100)
	// 	ft_many_nbrs(all, a);
}
