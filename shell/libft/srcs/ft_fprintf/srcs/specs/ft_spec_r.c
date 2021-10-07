/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_r.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:55:45 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/11 17:57:15 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

int	ft_spec_r(t_modifiers modifiers)
{
	int		n;
	char	fill;

	n = 1;
	if (modifiers.flags[zero])
		fill = '0';
	else
		fill = ' ';
	if (modifiers.flags[minus])
		ft_putchar_fd('%', modifiers.fd);
	while (modifiers.width - 1 > 0)
	{
		ft_putchar_fd(fill, modifiers.fd);
		modifiers.width--;
		n++;
	}
	if (!modifiers.flags[minus] || modifiers.flags[zero])
		ft_putchar_fd('%', modifiers.fd);
	return (n);
}
