#include "push_swap.h"

void	ft_read_argvs(int argc, char **argv, t_all *all)
{
	int x;
	int i;
	int count;
	
	i = 0;
	x = 1;
	count = 0;

	// stack->size = argc;
	// printf("stack size: %d\n", stack->size);
	// stack->a = (int *)calloc(sizeof(int *), 7);
	// if (!stack->a)
	// 	printf("non ha allocato memoria su A\n");
	// stack->b = (int *)calloc(sizeof(int *), 7);
	// if (!stack->b)
	// 	printf("non ha allocato memoria su B\n");

	//printf("memoria allocata");
	// while (x < argc)
	// {
	// 	i = 0;
	// 	while (argv[x])
	// 	{
	// 		all->a->nbrs[i] = atoi(&argv[x][count]);
	// 		count += ft_numlen(all->a->nbrs[i]);
	// 		//printf("%d\n", stack->a[i]);
	// 		i++;
	// 	}
	// 	x++;
	// }
}

int	ft_numlen(int n)
{
	int i;
	
	i = 1;
	//printf("numero da contare: %d\n", n);
	if (n < 0)
		i += 1;
	if (n <= 9)
	{
		//printf("lunghezza numero: %d = %d\n", n, i);
		return(i);
	}
	//printf("lunghezza numero: %d = %d\n", n, (i + ft_numlen(n / 10)));
	return (i + ft_numlen(n / 10));
}