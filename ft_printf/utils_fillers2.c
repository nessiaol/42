/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fillers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 18:15:37 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/23 18:16:46 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_sup_right_positive(t_struct *list)
{
	list->zero = 0;
	list->fill_width = ft_filler(list, (list->type_lenght));
	if (list->type_arg_p != list->meno_uno)
	{
		list->precision = 2;
		ft_putstr(list, "0x");
		list->precision = 0;
	}
}

void		ft_sup_right_negative_one(t_struct *list)
{
	list->zero = 0;
	list->fill_width = ft_filler(list, (list->precision + 1));
	ft_putminus(list);
	list->zero = 1;
	list->fill_prec = ft_filler_precision(list);
}

void		ft_sup_right_negative_two(t_struct *list)
{
	list->zero = 0;
	list->fill_width = ft_filler(list, (list->type_lenght + 1));
	ft_putminus(list);
}
