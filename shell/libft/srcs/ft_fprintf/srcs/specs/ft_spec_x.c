/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:32:58 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/11 17:57:15 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static void	ft_print_unum(t_modifiers modifiers, int i)
{
	if (modifiers.upper_x)
		ft_putunbr_base_fd(i, "0123456789ABCDEF", modifiers.fd);
	else
		ft_putunbr_base_fd(i, "0123456789abcdef", modifiers.fd);
}

static int	ft_write_width(int len, t_modifiers modifiers)
{
	int		n;
	char	fill;

	n = 0;
	if (modifiers.flags[zero])
		fill = '0';
	else
		fill = ' ';
	while (modifiers.width - len > 0)
	{
		ft_putchar_fd(fill, modifiers.fd);
		modifiers.width--;
		n++;
	}
	return (n);
}

static int	ft_write_prec(unsigned int *i, int len, t_modifiers modifiers)
{
	int	n;

	n = 0;
	if (!(*i) && !modifiers.precision)
		return (n);
	while (modifiers.precision - len > 0)
	{
		ft_putchar_fd('0', modifiers.fd);
		modifiers.precision--;
		n++;
	}
	return (n);
}

static int	ft_spec_manager(unsigned int i, int n, t_modifiers modifiers)
{
	int	len;

	len = n;
	if (modifiers.flags[minus])
	{
		n += ft_write_prec(&i, len, modifiers);
		if (!(!i && !modifiers.precision))
			ft_print_unum(modifiers, i);
	}
	if (modifiers.precision > len)
		n += ft_write_width(modifiers.precision, modifiers);
	else
		n += ft_write_width(len, modifiers);
	if (!modifiers.flags[minus] || modifiers.flags[zero])
	{
		n += ft_write_prec(&i, len, modifiers);
		if (!(!i && !modifiers.precision))
			ft_print_unum(modifiers, i);
	}
	return (n);
}

int	ft_spec_x(va_list *args, t_modifiers modifiers)
{
	unsigned int	i;
	int				n;

	i = va_arg(*args, unsigned int);
	if (!modifiers.precision && !modifiers.width && !i)
		return (0);
	n = ft_unumlen_base(i, 16);
	if (!i && !modifiers.precision)
		n = 0;
	n = ft_spec_manager(i, n, modifiers);
	return (n);
}
