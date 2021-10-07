/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 16:42:27 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/01 22:26:04 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace_string(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (!ft_isspace(s[i]))
			return (0);
		i++;
	}
	return (1);
}
