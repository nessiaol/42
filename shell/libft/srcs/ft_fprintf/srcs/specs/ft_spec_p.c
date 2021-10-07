/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:21:57 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/11 17:57:15 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

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

static int	ft_write_prec(int len, t_modifiers modifiers)
{
	int	n;

	n = 0;
	while (modifiers.precision - len > 0)
	{
		ft_putchar_fd('0', modifiers.fd);
		modifiers.precision--;
		n++;
	}
	return (n);
}

static int	ft_spec_manager(unsigned long i, int n, t_modifiers modifiers)
{
	int	len;

	len = n;
	if (modifiers.flags[minus])
	{
		ft_putstr_fd("0x", modifiers.fd);
		n += ft_write_prec(len - 2, modifiers);
		if (modifiers.precision || i)
			ft_putunbr_base_fd(i, "0123456789abcdef", modifiers.fd);
	}
	if (modifiers.precision > len)
		n += ft_write_width(modifiers.precision, modifiers);
	else
		n += ft_write_width(len, modifiers);
	if (!modifiers.flags[minus] || modifiers.flags[zero])
	{
		ft_putstr_fd("0x", modifiers.fd);
		n += ft_write_prec(len - 2, modifiers);
		if (modifiers.precision || i)
			ft_putunbr_base_fd(i, "0123456789abcdef", modifiers.fd);
	}
	return (n);
}

int	ft_spec_p(va_list *args, t_modifiers modifiers)
{
	unsigned long	i;
	int				n;

	i = (unsigned long)va_arg(*args, void *);
	n = ft_ulnumlen_base(i, 16) + 2;
	if (!modifiers.precision && !i)
		n = 2;
	n = ft_spec_manager(i, n, modifiers);
	return (n);
}
