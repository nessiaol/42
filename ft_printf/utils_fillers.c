/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fillers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:08:13 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/23 17:19:16 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_left_negative_d(t_struct *list)
{
	if (list->precision >= list->type_lenght)
	{
		list->zero = 0;
		list->fill_width = ft_filler(list, (list->precision + 1));
		return (list->fill_prec + list->fill_width);
	}
	if (list->precision >= 0 && list->precision < list->type_lenght)
	{
		list->zero = 0;
		list->fill_width = ft_filler(list, (list->type_lenght));
		return (list->fill_prec + list->fill_width);
	}
	if (list->precision == -1)
	{
		return (ft_filler(list, list->type_lenght));
	}
	else
		return (0);
}

int			ft_left_positive_d(t_struct *list)
{
	if (list->precision > list->type_lenght)
	{
		list->zero = 0;
		list->fill_width = ft_filler(list, (list->precision));
		return (list->fill_prec + list->fill_width);
	}
	if (list->precision >= 0 && list->precision <= list->type_lenght)
	{
		list->zero = 0;
		list->fill_width = ft_filler(list, (list->type_lenght));
		return (list->fill_width);
	}
	if (list->precision == -1)
		return (ft_filler(list, list->type_lenght));
	else
		return (0);
}

int			ft_right_negative_d(t_struct *list)
{
	if (list->precision > list->type_lenght)
	{
		ft_sup_right_negative_one(list);
		return (list->fill_prec + list->fill_width);
	}
	if (list->precision >= 0 && list->precision <= list->type_lenght)
	{
		ft_sup_right_negative_two(list);
		return (list->fill_prec + list->fill_width);
	}
	if (list->precision == -1 && list->zero == 1)
	{
		ft_putminus(list);
		return (ft_filler(list, list->type_lenght));
	}
	if (list->precision == -1 && list->zero == 0)
	{
		list->fill_width = ft_filler(list, list->type_lenght + 1);
		ft_putminus(list);
		return (list->fill_width);
	}
	else
		return (0);
}

int			ft_right_positive_d(t_struct *list)
{
	if (list->precision > list->type_lenght)
	{
		list->zero = 0;
		list->fill_width = ft_filler(list, (list->precision));
		list->zero = 1;
		if (list->type_arg_p != list->meno_uno)
			ft_putstr(list, "0x");
		list->fill_prec = ft_filler_precision(list);
		return (list->fill_prec + list->fill_width);
	}
	if (list->precision >= 0 && list->precision <= list->type_lenght)
	{
		ft_sup_right_positive(list);
		return (list->fill_width);
	}
	else if (list->precision == -1)
	{
		list->fill_width = ft_filler(list, list->type_lenght);
		if (list->type_arg_p != list->meno_uno)
			ft_putstr(list, "0x");
		return (list->fill_width);
	}
	else
		return (0);
}
