/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 12:16:31 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/11 17:57:15 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_spec_c(va_list *args, t_modifiers modifiers)
{
	char	c;
	int		n;
	char	fill;

	c = va_arg(*args, int);
	n = 1;
	if (modifiers.flags[zero])
		fill = '0';
	else
		fill = ' ';
	if (modifiers.flags[minus])
		ft_putchar_fd(c, modifiers.fd);
	while (modifiers.width - 1 > 0)
	{
		ft_putchar_fd(fill, modifiers.fd);
		modifiers.width--;
		n++;
	}
	if (!modifiers.flags[minus] || modifiers.flags[zero])
		ft_putchar_fd(c, modifiers.fd);
	return (n);
}
