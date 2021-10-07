/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:53:41 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/22 11:28:22 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	long	i;

	i = ft_strlen(s);
	if (!s)
		return (0);
	while (i > 0)
	{
		if ((char)s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	if ((char)s[0] == (char)c)
		return ((char *)(s + i));
	return (0);
}
