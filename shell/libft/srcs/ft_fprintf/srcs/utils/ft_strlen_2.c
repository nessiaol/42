/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 13:51:58 by cserapon          #+#    #+#             */
/*   Updated: 2021/03/30 16:31:11 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
