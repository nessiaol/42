/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulnumlen_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:43:52 by cserapon          #+#    #+#             */
/*   Updated: 2021/03/30 16:31:32 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ulnumlen_base(unsigned long i, int base)
{
	int	n;

	if (i != 0)
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
