/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnastro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:08:46 by gnastro           #+#    #+#             */
/*   Updated: 2021/05/19 15:49:39 by gnastro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checka(int *a, int n)
{
	int		i;

	i = 0;
	while (i < n - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	checkb(int *b, int n)
{
	int		i;

	i = 0;
	while (i < n - 1)
	{
		if (b[i] < b[i + 1])
			return (0);
		i++;
	}
	return (1);
}
