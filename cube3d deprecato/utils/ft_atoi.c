/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:58:50 by bde-luca          #+#    #+#             */
/*   Updated: 2021/01/25 11:35:24 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int						ft_atoi(const char *str)
{
	unsigned int		num;
	int					sign;

	sign = 1;
	num = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*(str++) == '-')
			sign *= -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*(str++) - '0');
		if (num > 2147483647)
			break ;
	}
	if ((num > 2147483648) && (sign == -1))
		return (0);
	else if ((num > 2147483647) && (sign == 1))
		return (-1);
	else
		return (num * sign);
}
