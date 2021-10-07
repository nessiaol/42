/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:51:01 by cserapon          #+#    #+#             */
/*   Updated: 2021/03/31 18:35:54 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static long	ft_jump_spaces(const char *str, long i)
{
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	return (i);
}

static void	ft_check_sign(const char *str, long *i, int *sign)
{
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign = -1;
		(*i)++;
	}
}

long	ft_atol(const char *str)
{
	long				i;
	int					sign;
	unsigned long long	number;

	sign = 1;
	number = 0;
	i = ft_jump_spaces(str, 0);
	ft_check_sign(str, &i, &sign);
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (number >= 0xffffffffffffffff / 10 && sign == 1)
			return (-1);
		else if (number >= 0xfffffffffffffff / 10 && sign == -1)
			return (0);
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number * sign);
}
