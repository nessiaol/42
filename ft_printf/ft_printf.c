/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:24:52 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/23 15:34:44 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libftprintf.h"

void	ft_init_struct(t_struct *list)
{
	list->minus = 0;
	list->zero = 0;
	list->width = 0;
	list->precision = -1;
	list->type_lenght = 0;
	list->type_char = '0';
	list->fillers = 0;
	list->num_neg = 0;
	list->fill_width = 0;
	list->fill_prec = 0;
	list->type_arg_p = -1;
	list->meno_uno = -1;
}

void	ft_parse(t_struct *list, const char *str, va_list argptr, int *i)
{
	while (str[*i] != '\0' && list->type_char == '0')
	{
		ft_check_minus(list, str, i);
		ft_check_zero(list, str, i);
		ft_check_width(list, str, argptr, i);
		ft_check_precision(list, str, argptr, i);
		ft_check_type(list, str, i);
		if (list->type_char != '0')
			break ;
		(*i)++;
	}
	(*i)--;
	ft_alignment(list, argptr);
}

int		ft_sup_printf(t_struct *list, const char *str, va_list argptr, int *i)
{
	int	y;

	y = 0;
	while (str[*i] != '\0')
	{
		if (str[*i] != '%')
		{
			ft_putchar(str[*i]);
			y++;
		}
		else
		{
			ft_init_struct(list);
			(*i)++;
			ft_parse(list, str, argptr, i);
			if (list->type_arg_p != list->meno_uno)
				y += 2;
			y = y + (list->format_lenght);
		}
		(*i)++;
	}
	return (y);
}

int		ft_printf(const char *str, ...)
{
	va_list		argptr;
	t_struct	list;
	int			i;
	int			y;

	i = 0;
	y = 0;
	va_start(argptr, str);
	y = ft_sup_printf(&list, str, argptr, &i);
	va_end(argptr);
	return (y);
}
