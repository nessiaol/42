/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 15:07:13 by cserapon          #+#    #+#             */
/*   Updated: 2021/01/12 15:14:11 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	i = 0;
	j = 0;
	while (dst[j])
		j++;
	while (i + dstlen + 1 < dstsize && src[i])
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	if (dstsize > dstlen)
		return (dstlen + ft_strlen(src));
	return (dstsize + ft_strlen(src));
}
