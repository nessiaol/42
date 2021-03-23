/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_un_integers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:54:09 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/23 16:57:19 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_countnbr_u(t_struct *list, unsigned int nb)
{
	int		len;
	int		i;
	int		a[11];

	i = 0;
	if (nb == 0)
	{
		if (list->precision == 0)
			i = 0;
		else
			i = 1;
	}
	if (nb > 0)
	{
		while (nb != 0)
		{
			a[i] = (nb % 10);
			nb = nb / 10;
			i++;
		}
	}
	len = i;
	return (len);
}

void		ft_putnbr_u(t_struct *list, unsigned int nb)
{
	int		i;
	int		a[11];

	i = 0;
	if (nb == 0 && list->precision != 0)
		write(1, "0", 1);
	if (nb > 0)
	{
		while (nb != 0)
		{
			a[i] = (nb % 10) + '0';
			nb = nb / 10;
			i++;
		}
		a[i] = '\0';
		i--;
		while (i >= 0)
		{
			write(1, &a[i], 1);
			i--;
		}
	}
}
