#include "push_swap.h"

void ft_bubblesort(t_all *all, t_stack *a)
{
	int i;
	int j;
	//stack->size = 7;

	i = 0;

	while (i < (all->size - 1)) //controlla fino a che non finiscono i numeri
	{
		j = (all->size - 1);	// n-1 è l'ultima componente dell'array.
		while(j > i)
		{
			if (a->nbrs[j] < a->nbrs[j-1])
			{
				ft_swap(&a->nbrs[j],&a->nbrs[j-1]);
				//printf("sa\n");
				//all->moves++;
			}
			j--;
		}
		i++;
	}
}

void ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

//-------------------------------------- da sistemare con le stack a e b
/*
void	ft_swap_s(t_all *all, int i, int j)
{
	i = 1;
	printf("entra in swap s\n");
	// if ((stack->a[j] < stack->a[j-1]) && (stack->b[j] < stack->b[j-1]))
	// {
	// 	ft_swap(&stack->a[j],&stack->a[j-1]);
	// 	ft_swap(&stack->b[j],&stack->b[j-1]);
	// 	printf("ss\n");
	// }			
	// if (all->stack->a[j] < stack->a[j-1])
	// {
	// 	ft_swap(&stack->a[j],&stack->a[j-1]);
	// 	printf("sa\n");
	// }
	// else if (stack->b[j] < stack->b[j-1])
	// {
	// 	ft_swap(&stack->b[j],&stack->b[j-1]);
	// 	printf("sa\n");
	// }			
}*/