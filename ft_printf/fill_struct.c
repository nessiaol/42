/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:59:03 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/23 16:01:05 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_check_minus(t_struct *list, const char *str, int *i)
{
	if (str[*i] == '-')
	{
		list->minus = 1;
		(*i)++;
	}
}

void	ft_check_zero(t_struct *list, const char *str, int *i)
{
	if (str[*i] == '0')
	{
		list->zero = 1;
		(*i)++;
		if (str[*i] == '-')
		{
			list->minus = 1;
			list->zero = 0;
			(*i)++;
		}
	}
}

void	ft_check_width(t_struct *list, const char *str,
		va_list argptr, int *i)
{
	if (str[*i] == '*')
	{
		list->width = va_arg(argptr, int);
		(*i)++;
	}
	if (ft_isdigit(str[*i]))
	{
		list->width = ft_atoi(&str[*i], i);
	}
}

void	ft_check_precision(t_struct *list, const char *str,
		va_list argptr, int *i)
{
	if (str[*i] == '.')
	{
		(*i)++;
		if (str[*i] == '*')
		{
			list->precision = va_arg(argptr, int);
			if (list->precision < 0)
				list->precision = -1;
			(*i)++;
		}
		else if (ft_isdigit(str[*i]))
		{
			list->precision = ft_atoi(&str[*i], i);
		}
		else
			list->precision = 0;
	}
}

void	ft_check_type(t_struct *list, const char *str, int *i)
{
	if (str[*i] == 'c' || str[*i] == 's' || str[*i] == 'p' ||
		str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'u' ||
		str[*i] == 'x' || str[*i] == 'X' || str[*i] == '%')
	{
		list->type_char = str[*i];
		(*i)++;
	}
}
