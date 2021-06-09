/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnastro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:08:46 by gnastro           #+#    #+#             */
/*   Updated: 2021/05/19 17:11:16 by gnastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	dub_check(int ac, int *num)		/* checka i duplicati*/
{
	int		i;
	int		j;

	j = 0;
	if (ac > 1)
	{
		while (++j < ac)
		{
			i = 0;
			while (i < j)
			{
				if (num[i] == num[j])
				{
					ft_putendl("Error dup");
					printf("%d", num[i]);
					exit(0);
				}
				i++;
			}
		}
	}
}


void	place1(int *n, int *a, char **av)		/* questa è la funzione che converte in int un argv con un singolo numero*/
{
	a[n[1] - 1] = ft_atoi(av[n[2]]);
	if ((a[n[1] - 1])
		|| ft_strequ(av[n[2]], "0"))			//se atoi ha funzionato non fare nulla
	{
	}
	else
	{
		ft_putendl("Error");
		exit(0);
	}
}


void	place2(int *n, int *a, char **av)		/* questa è la funzione che converte in int piu' numeri*/
{
	int		i;

	i = 0;
	while (i < n[0])
	{
		a[n[2]] = ft_atoi(av[i]);
		if (a[n[2]] || ft_strequ(av[i], "0"))
		{
			n[2]++;
			i++;
		}
		else
		{
			ft_putendl("Error");
			exit(0);
		}
	}
}

void	erpl2(int *a, int *x, char **tmp)
{
	place2(x, a, tmp);
	dub_check(x[1], a);
}

void	erpl1(int *a, int *x, char **tmp)
{
	place1(x, a, tmp);
	dub_check(x[1], a);
}
