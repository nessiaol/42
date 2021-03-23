/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:03:44 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/12 12:03:52 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_puthexa_upper(t_struct *list, size_t n)
{
	char	hexadecinum[100];
	int		i;
	int		temp;

	i = 0;
	temp = 0;
	if (list->type_arg_xup == 0 && list->precision != 0)
		write(1, "0", 1);
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			hexadecinum[i] = temp + '0';
		else
			hexadecinum[i] = temp + 'A' - 10;
		i++;
		n = n / 16;
	}
	while (--i >= 0)
	{
		write(1, &hexadecinum[i], 1);
	}
}

void		ft_puthexa_lower(t_struct *list, size_t n)
{
	char	hexadecinum[100];
	int		i;
	int		temp;

	i = 0;
	temp = 0;
	if (n > 0)
	{
		while (n != 0)
		{
			temp = n % 16;
			if (temp < 10)
				hexadecinum[i] = temp + '0';
			else
				hexadecinum[i] = temp + 'a' - 10;
			i++;
			n = n / 16;
		}
		while (--i >= 0)
			write(1, &hexadecinum[i], 1);
	}
	else if (list->precision != 0)
		write(1, "0", 1);
}
