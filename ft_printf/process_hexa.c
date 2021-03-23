/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 12:03:44 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/23 16:47:14 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			ft_hexa_lower(char *hexadecinum, int len, int i, size_t n)
{
	int		temp;

	temp = 0;
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			hexadecinum[i] = temp + '0';
		else
			hexadecinum[i] = temp + 'a' - 10;
		i++;
		n = n / 16;
	}
	len = i;
	while (i >= 0)
	{
		i--;
	}
	return (len);
}

int			ft_counthexa_lower(t_struct *list, size_t n)
{
	char	hexadecinum[100];
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (n == 0)
	{
		if (list->precision == 0)
			len = 0;
		else
			len = 1;
	}
	else
		len = ft_hexa_lower(hexadecinum, len, i, n);
	return (len);
}

int			ft_hexa_upper(char *hexadecinum, int len, int i, size_t n)
{
	int		temp;

	temp = 0;
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			hexadecinum[i] = temp + '0';
		else
			hexadecinum[i] = temp + 'A' - 10;
		i++;
		n = n / 16;
	}
	len = i;
	while (i >= 0)
	{
		i--;
	}
	return (len);
}

int			ft_counthexa_upper(t_struct *list, size_t n)
{
	char	hexadecinum[100];
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (n == 0)
	{
		if (list->precision == 0)
			len = 0;
		else
			len = 1;
	}
	else
		len = ft_hexa_upper(hexadecinum, len, i, n);
	return (len);
}
