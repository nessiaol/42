/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:18:01 by dmangola          #+#    #+#             */
/*   Updated: 2021/05/13 19:33:32 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_all *all, t_stack *a)
{
	int i;

	i = 0;
	while (i < all->size)
	{
		printf("%10d\n", a->nbrs[i]);
		i++;
	}
	printf("\n");
}

int	ft_count_numbers(char const *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			words++;
		}
		i++;
	}
	return (words);
}



int main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_all		all;

	if (argc > 1)
	{
		int i;
		int j;
		int x;
		int y;
		char    **tmp;

		i = 0;
		x = 1;
		y = 0;
		j = 0;
		all.size = 0;
//			-------STAMPA GLI ARGOMENTI
		while (x < argc)
		{
			printf("argv x: [%s]\n", argv[x]);
			x++;
		}
		printf("\n");

//			------CONTA GLI SLOT PER LA STACK
		x = 1;
	
		while (argv[x])
		{
			all.size += ft_count_numbers(argv[x], ' ');
			x++;
		}
		printf("\nstack size: %d\n", all.size);

//			------DIVIDE GLI ARGOMENTI, LI TRASFORMA IN INT E LI METTE NELLA STACK
		
		a.nbrs = (int *)calloc(sizeof(int *), all.size-1);
		b.nbrs = (int *)calloc(sizeof(int *), all.size-1);

		x = 1;
		i = 0;

		while (argv[x])
		{
			printf("argv x: %s\n", argv[x]);
		    tmp = ft_split(argv[x], ' ');
			
			while (i < all.size)
			{
				printf("temp: %s - ", tmp[i]);
				a.nbrs[i] = atoi(tmp[i]);
				printf("numero in stack a: %d\n", a.nbrs[i]);
				i++;
			}			
			x++;
		}
		printf("stack size: %d\n\n", all.size);

		
		//printf("i:%d x:%d\n", i, x);

		// ft_init(&stack);
				
		printf("***** UNORDERED stack a:\n"); 
		ft_print_stack(&all, &a);
		
		ft_bubblesort(&all, &a);

		printf("***** ORDERED stack a: \n"); 
		ft_print_stack(&all, &a);

		ft_rotate(&all, &a);
		printf("***** ROTATE stack a: \n"); 
		ft_print_stack(&all, &a);

		ft_rotate_rev(&all, &a);
		printf("***** REVERSE ROTATE stack a: \n"); 
		ft_print_stack(&all, &a);

		ft_rotate_rev(&all, &a);
		printf("***** REVERSE ROTATE stack a: \n"); 
		ft_print_stack(&all, &a);

		printf("moves: %d\n", all.moves);
	}
	return (0);
}
