/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:19:15 by cserapon          #+#    #+#             */
/*   Updated: 2021/03/30 16:31:55 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_unumlen_base(unsigned int i, int base)
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
