/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isescaped.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:26:52 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/14 18:11:14 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isescaped(char *line, int i)
{
	int	bkslhs;

	bkslhs = 0;
	if (i < 0)
		return (0);
	while (i && line[i] == '\\')
	{
		++bkslhs;
		--i;
	}
	if (bkslhs % 2 == 0)
		return (0);
	return (1);
}
