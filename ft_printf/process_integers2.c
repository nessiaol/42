/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_integers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:50:48 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/23 16:53:59 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_output(int nb)
{
	int		i;
	int		a[11];
	int		len;

	i = 0;
	while (nb != 0)
	{
		a[i] = (nb % 10);
		nb = nb / 10;
		i++;
	}
	len = i;
	return (len);
}

int			ft_countnbr(t_struct *list, int nb)
{
	int		len;
	int		minus;

	minus = 0;
	if (nb == -2147483648)
	{
		len = 10;
		list->num_neg = 1;
	}
	if (nb == 0)
	{
		if (list->precision == 0)
			len = 0;
		else
			len = 1;
	}
	if (nb < 0 && nb != -2147483648)
	{
		nb = -nb;
		list->num_neg = 1;
	}
	if (nb > 0)
		len = ft_output(nb);
	return (len + minus);
}

void		ft_check_num_neg(t_struct *list)
{
	if (list->type_arg_d < 0)
		list->num_neg = 1;
}
