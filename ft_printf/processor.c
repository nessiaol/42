/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:27:25 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/23 16:38:48 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_alignment(t_struct *list, va_list argptr)
{
	if (list->width < 0)
	{
		list->width *= -1;
		list->minus = 1;
	}
	if (list->minus == 1)
		ft_left_aligned(list, argptr);
	else
		ft_right_aligned(list, argptr);
}

void	ft_left_aligned(t_struct *list, va_list argptr)
{
	ft_process_type(argptr, list);
	if ((list->type_char) == 'd' || (list->type_char) == 'i' ||
		(list->type_char) == 'x' || (list->type_char) == 'X' ||
		(list->type_char) == 'u' || (list->type_char) == 'p')
	{
		if (list->num_neg == 1)
			ft_putminus(list);
		if (list->precision >= list->type_lenght)
		{
			list->zero = 1;
			list->minus = 0;
			list->fill_prec = ft_filler_precision(list);
		}
	}
	if (list->type_arg_p != list->meno_uno)
		ft_putstr(list, "0x");
	ft_print_type(list);
	list->fillers = ft_left_check_fillers(list);
	list->format_lenght = (list->type_lenght) + (list->fillers);
}

void	ft_right_aligned(t_struct *list, va_list argptr)
{
	ft_process_type(argptr, list);
	list->fillers = ft_right_check_fillers(list);
	ft_print_type(list);
	list->format_lenght = (list->type_lenght) + (list->fillers);
}

int		ft_right_check_fillers(t_struct *list)
{
	int	total_fillers;

	total_fillers = 0;
	if ((list->type_char) == 'd' || (list->type_char) == 'i' ||
		(list->type_char) == 'x' || (list->type_char) == 'X' ||
		(list->type_char) == 'u' || (list->type_char) == 'p')
	{
		if (list->num_neg == 1)
			total_fillers = ft_right_negative_d(list);
		else
			total_fillers = ft_right_positive_d(list);
		return (total_fillers);
	}
	if ((list->type_char) == 's' || (list->type_char) == 'c' ||
		(list->type_char) == '%')
	{
		total_fillers = ft_filler(list, (list->type_lenght));
		return (total_fillers);
	}
	else
		return (0);
}

int		ft_left_check_fillers(t_struct *list)
{
	int	total_fillers;

	total_fillers = 0;
	if ((list->type_char) == 'd' || (list->type_char) == 'i' ||
		(list->type_char) == 'x' || (list->type_char) == 'X' ||
		(list->type_char) == 'u' || (list->type_char) == 'p')
	{
		if (list->num_neg == 1)
			total_fillers = ft_left_negative_d(list);
		else
			total_fillers = ft_left_positive_d(list);
		return (total_fillers);
	}
	if ((list->type_char) == 's' || (list->type_char) == 'c' ||
		(list->type_char) == '%')
	{
		total_fillers = ft_filler(list, (list->type_lenght));
		return (total_fillers);
	}
	else
		return (0);
}
