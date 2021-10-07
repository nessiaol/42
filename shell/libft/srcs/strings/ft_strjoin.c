/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:31:45 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/25 11:46:57 by cserapon        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		firstlen;
	int		secondlen;

	if (!s1 || !s2)
		return (0);
	firstlen = ft_strlen(s1);
	secondlen = ft_strlen(s2);
	s = (char *)ft_calloc(firstlen + secondlen + 1, sizeof(char));
	if (!s)
		return (0);
	ft_strlcpy(s, s1, ft_strlen(s1) + 1);
	ft_strlcpy((char *)(s + ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	return (s);
}
