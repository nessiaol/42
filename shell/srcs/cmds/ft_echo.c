/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:21:28 by dmangola          #+#    #+#             */
/*   Updated: 2021/09/05 16:21:30 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ashella.h"

int	ft_echo(char **av)
{
	int		flag;
	int		written;
	int		i;

	i = 0;
	written = 0;
	flag = 0;
	while (av[++i])
	{
		if(!ft_strncmp(av[i], "-n", ft_strlen(av[i])) && i == 1)
			flag = 1;
		else if (ft_strncmp(av[i], "-n", ft_strlen(av[i])) || written == 1)
		{
			if (written == 1)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(av[i], 1);
			written = 1;
		}
	}
	if (flag == 0)
		ft_putchar_fd('\n', 1);
	return (0);
}