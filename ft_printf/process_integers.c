/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_integers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 16:48:18 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/23 16:50:37 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_output(int nb)
{
	int		i;
	int		a[11];
	int		len;

	i = 0;
	while (nb != 0)
	{
		a[i] = (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	a[i] = '\0';
	i--;
	len = i;
	while (i >= 0)
	{
		write(1, &a[i], 1);
		i--;
	}
	return (len);
}

int				ft_putnbr(t_struct *list, int nb)
{
	int		len;
	int		minus;

	minus = 0;
	if (nb == -2147483648)
	{
		write(1, "2147483648", 10);
		len = 10;
	}
	if (nb == 0 && list->precision != 0)
		write(1, "0", 1);
	if (nb < 0 && nb != -2147483648)
	{
		nb = -nb;
		minus = 1;
	}
	if (nb > 0)
		len = ft_output(nb);
	return (len + minus);
}

int				ft_atoi(const char *str, int *i)
{
	unsigned int		num;

	num = 0;
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*(str++) - '0');
		if (num > 2147483647)
			break ;
		(*i)++;
	}
	return (num);
}
