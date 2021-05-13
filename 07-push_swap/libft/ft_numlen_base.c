/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:06:00 by dmangola          #+#    #+#             */
/*   Updated: 2021/02/27 16:06:57 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen_base(int num, int base)
{
	int	len;

	if (num == -2147483648)
		return (11);
	if (num > 0)
		len = 0;
	else
		len = 1;
	while (num)
	{
		num /= base;
		len++;
	}
	return (len);
}
