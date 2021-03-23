/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:45:14 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/23 16:58:33 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_process_type(va_list argptr, t_struct *list)
{
	if ((list->type_char) == 'c' || (list->type_char) == 's' ||
		(list->type_char) == '%')
		ft_process_type_one(argptr, list);
	if ((list->type_char) == 'd' || (list->type_char) == 'i' ||
		(list->type_char) == 'u')
		ft_process_type_two(argptr, list);
	if ((list->type_char) == 'p' || (list->type_char) == 'x' ||
		(list->type_char) == 'X')
		ft_process_type_three(argptr, list);
}

void	ft_process_type_one(va_list argptr, t_struct *list)
{
	if ((list->type_char) == 'c')
	{
		list->type_arg_c = (va_arg(argptr, int));
		list->type_lenght = 1;
	}
	if ((list->type_char) == 's')
	{
		if (list->minus == 1)
			list->zero = 0;
		list->type_arg_s = va_arg(argptr, char*);
		if (list->type_arg_s == NULL)
			list->type_lenght = ft_strlen(list, "(null)");
		else
			list->type_lenght = ft_strlen(list, (list->type_arg_s));
	}
	if ((list->type_char) == '%')
	{
		list->type_arg_c = '%';
		list->type_lenght = 1;
	}
}

void	ft_process_type_two(va_list argptr, t_struct *list)
{
	if ((list->type_char) == 'd' || (list->type_char) == 'i')
	{
		list->type_arg_d = va_arg(argptr, int);
		ft_check_num_neg(list);
		list->type_lenght = ft_countnbr(list, list->type_arg_d);
	}
	if ((list->type_char) == 'u')
	{
		list->type_arg_u = va_arg(argptr, unsigned int);
		list->type_lenght = ft_countnbr_u(list, list->type_arg_u);
	}
}

void	ft_process_type_three(va_list argptr, t_struct *list)
{
	if ((list->type_char) == 'x')
	{
		list->type_arg_x = va_arg(argptr, unsigned int);
		list->type_lenght = ft_counthexa_lower(list, list->type_arg_x);
	}
	if ((list->type_char) == 'X')
	{
		list->type_arg_xup = va_arg(argptr, unsigned int);
		list->type_lenght = ft_counthexa_upper(list, list->type_arg_xup);
	}
	if ((list->type_char) == 'p')
	{
		list->type_arg_p = va_arg(argptr, size_t);
		if (!list->type_arg_p && list->precision != 0)
			list->type_lenght = 1;
		else if (!list->type_arg_p && list->precision == 0)
			list->type_lenght = 0;
		else
			list->type_lenght = ft_counthexa_lower(list, list->type_arg_p);
	}
}
