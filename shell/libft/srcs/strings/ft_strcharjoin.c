/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcharjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 12:10:49 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/15 17:30:33 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcharjoin(char *old, char c)
{
	char	*new;
	int		i;

	if (!old)
		new = (char *)ft_calloc(2, sizeof(char));
	else
		new = (char *)ft_calloc(ft_strlen(old) + 2, sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (old && old[i])
	{
		new[i] = old[i];
		i++;
	}
	new[i] = c;
	ft_if_free((void **)&old);
	return (new);
}
