/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:44:27 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/15 13:21:37 by dmangola         ###   ########.fr       */
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
