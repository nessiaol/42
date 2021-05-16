/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:18:01 by dmangola          #+#    #+#             */
/*   Updated: 2021/05/16 16:05:39 by bde-luca         ###   ########.fr       */
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
		int x;
		char    **tmp;
		int quotes;

		i = 0;		//counter per atoi
		x = 1;		//counter per gli argomenti

		ft_init(&all);		//inizializza size e moves
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

//			------CREA LA MEMORIA PER LA STACK
		
		a.nbrs = (int *)calloc(sizeof(int *), all.size-1);
		b.nbrs = (int *)calloc(sizeof(int *), all.size-1);

		x = 1;		

//			------CONTROLLA SE CI SONO VIRGOLETTE E DIVIDE I NUMERI E LI METTE NELLA STACK A

		while (argv[x])
		{
			quotes = ft_checkquotes(argv[x]);
			if (quotes == 1)
			{
				printf("argv x: %s\n", argv[x]);
				tmp = ft_split(argv[x], ' ');
				
				while (i < all.size)
				{
					printf("[%d] temp: %5s - ", i, tmp[i]);
					a.nbrs[i] = atoi(tmp[i]);
					printf("numero in stack a: %5d\n", a.nbrs[i]);
					i++;
				}
			}
			else
					a.nbrs[i] = atoi(argv[x]);
			i++;
			x++;
		}
		
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
