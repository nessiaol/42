/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:47:44 by cserapon          #+#    #+#             */
/*   Updated: 2021/03/30 16:29:13 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_numlen_base(int i, int base)
{
	int	n;

	if (i == -2147483648)
		return (11);
	if (i > 0)
		n = 0;
	else
		n = 1;
	while (i)
	{
		i /= base;
		n++;
	}
	return (n);
}
