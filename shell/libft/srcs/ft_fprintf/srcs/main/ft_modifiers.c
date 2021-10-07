/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifiers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:06:15 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/11 17:57:15 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static void	ft_check_precision(va_list *args, const char *format, int *i,
		t_modifiers *modifiers)
{
	if (format[*i] != '.')
		return ;
	(*i)++;
	if (format[*i] == '*')
	{
		modifiers->precision = va_arg(*args, int);
		(*i)++;
	}
	else if (ft_isdigit(format[*i]))
		modifiers->precision = ft_special_atoi(format, i);
	else
		modifiers->precision = 0;
	while (1)
	{
		if (ft_isdigit(format[*i]))
			(*i)++;
		else if (format[*i] == '*')
		{
			va_arg(*args, int);
			(*i)++;
		}
		else
			return ;
	}
}

static void	ft_check_width(va_list *args, const char *format, int *i,
		t_modifiers *modifiers)
{
	while (1)
	{
		if (ft_isdigit(format[*i]))
		{
			modifiers->width_state = true;
			modifiers->width = ft_special_atoi(format, i);
		}
		else if (format[*i] == '*')
		{
			modifiers->width_state = true;
			modifiers->width = va_arg(*args, int);
			(*i)++;
		}
		else
		{
			if (modifiers->width < 0 && modifiers->width_state)
			{
				modifiers->flags[minus] = true;
				modifiers->width *= -1;
			}
			return ;
		}
	}
}

static void	ft_check_flags(const char *format, int *i, t_modifiers *modifiers)
{
	char	flagset[3];
	int		j;

	flagset[0] = '0';
	flagset[1] = '-';
	flagset[2] = 0;
	j = 0;
	while (flagset[j])
	{
		if (format[*i] == flagset[j])
		{
			modifiers->flags[j] = true;
			(*i)++;
			j = -1;
		}
		j++;
	}
}

void	ft_check_modifiers(va_list *args, const char *format, int *i,
		t_modifiers *modifiers)
{
	int	j;

	j = 0;
	while (j < 2)
		modifiers->flags[j++] = false;
	modifiers->width = -1;
	modifiers->width_state = false;
	modifiers->precision = -1;
	modifiers->upper_x = false;
	ft_check_flags(format, i, modifiers);
	ft_check_width(args, format, i, modifiers);
	ft_check_precision(args, format, i, modifiers);
	if (modifiers->flags[minus] || modifiers->precision > -1)
		modifiers->flags[zero] = false;
}
