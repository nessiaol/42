/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:19:42 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/23 17:23:01 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(t_struct *list, char *s)
{
	int	y;

	y = 0;
	while (s[y] != '\0')
	{
		if (y == (list->precision))
			return (y);
		y++;
	}
	return (y);
}

void	ft_putstr(t_struct *list, char *s)
{
	int	y;

	y = 0;
	while (s[y] != '\0')
	{
		if (y == (list->precision))
			break ;
		ft_putchar(s[y]);
		y++;
	}
}

int		ft_putstrlen(t_struct *list, char *s)
{
	int	y;

	y = 0;
	while (s[y] != '\0')
	{
		if (y == (list->precision))
			return (y);
		ft_putchar(s[y]);
		y++;
	}
	return (y);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}
