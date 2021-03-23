/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:58:46 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/23 17:07:42 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_filler(t_struct *list, int n)
{
	int	x;
	int	filling;

	x = 0;
	filling = ((list->width) - n);
	if (list->type_arg_p != list->meno_uno)
		filling -= 2;
	while (x < filling)
	{
		if (list->zero == 1 && list->minus == 0)
		{
			ft_putchar('0');
			x++;
		}
		else
		{
			ft_putchar(' ');
			x++;
		}
	}
	return (x);
}

int		ft_filler_precision(t_struct *list)
{
	int	x;
	int	filling;

	x = 0;
	filling = (list->precision - list->type_lenght);
	if (list->num_neg == 1)
		filling += 1;
	while (x < filling)
	{
		if (list->zero == 1 && list->minus == 0)
		{
			ft_putchar('0');
			x++;
		}
		else
		{
			ft_putchar(' ');
			x++;
		}
	}
	return (x);
}

void	ft_print_type(t_struct *list)
{
	if (list->type_char == 'c' || list->type_char == '%')
		ft_putchar(list->type_arg_c);
	if (list->type_char == 's')
	{
		if (list->type_arg_s == NULL)
			ft_putstr(list, "(null)");
		else
			ft_putstr(list, (list->type_arg_s));
	}
	if (list->type_char == 'd' || list->type_char == 'i')
		ft_putnbr(list, list->type_arg_d);
	if (list->type_char == 'x')
		ft_puthexa_lower(list, list->type_arg_x);
	if (list->type_char == 'X')
		ft_puthexa_upper(list, list->type_arg_xup);
	if (list->type_char == 'u')
		ft_putnbr_u(list, list->type_arg_u);
	if (list->type_char == 'p')
		ft_puthexa_lower(list, list->type_arg_p);
}

void	ft_putminus(t_struct *list)
{
	if (list->type_char == 'd' || list->type_char == 'i')
	{
		if (list->num_neg == 1)
		{
			ft_putchar('-');
			list->type_lenght += 1;
		}
	}
}
