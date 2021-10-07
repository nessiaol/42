/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:18:34 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/11 17:57:15 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

static int	ft_write_width(long *i, int len, t_modifiers modifiers)
{
	int		n;
	char	fill;

	n = 0;
	if (modifiers.flags[zero])
		fill = '0';
	else
		fill = ' ';
	if (modifiers.flags[zero] && (*i) < 0)
	{
		ft_putchar_fd('-', modifiers.fd);
		(*i) *= -1;
	}
	while (modifiers.width - len > 0)
	{
		ft_putchar_fd(fill, modifiers.fd);
		modifiers.width--;
		n++;
	}
	return (n);
}

static int	ft_write_prec(long *i, int len, t_modifiers modifiers)
{
	int	n;

	n = 0;
	if (!(*i) && !modifiers.precision)
		return (n);
	if ((*i) < 0)
	{
		ft_putchar_fd('-', modifiers.fd);
		(*i) *= -1;
	}
	while (modifiers.precision - len > 0)
	{
		ft_putchar_fd('0', modifiers.fd);
		modifiers.precision--;
		n++;
	}
	return (n);
}

static int	ft_spec_manager(long i, int n, t_modifiers modifiers)
{
	int	len;

	len = n;
	if (i < 0)
		modifiers.precision++;
	if (modifiers.flags[minus])
	{
		n += ft_write_prec(&i, len, modifiers);
		if (!(!i && !modifiers.precision))
			ft_putnbr_fd(i, modifiers.fd);
	}
	if (modifiers.precision > len)
		n += ft_write_width(&i, modifiers.precision, modifiers);
	else
		n += ft_write_width(&i, len, modifiers);
	if (!modifiers.flags[minus] || modifiers.flags[zero])
	{
		n += ft_write_prec(&i, len, modifiers);
		if (!(!i && !modifiers.precision))
			ft_putnbr_fd(i, modifiers.fd);
	}
	return (n);
}

int	ft_spec_d(va_list *args, t_modifiers modifiers)
{
	long	i;
	int		n;

	i = (long)va_arg(*args, int);
	if (!modifiers.precision && !modifiers.width && !i)
		return (0);
	n = ft_numlen_base(i, 10);
	if (!i && !modifiers.precision)
		n = 0;
	n = ft_spec_manager(i, n, modifiers);
	return (n);
}
