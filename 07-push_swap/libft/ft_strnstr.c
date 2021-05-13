/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:20:39 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/15 16:20:55 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;
	size_t	cc;
	char	*res;

	cc = 0;
	res = (char *)haystack;
	if (!(*needle))
		return (res);
	n_len = ft_strlen(needle);
	while (*res != '\0' && ((len - n_len) >= 0))
	{
		while (*(res + cc) == needle[cc])
		{
			cc++;
			if ((cc == n_len) && cc <= len)
				return (res);
		}
		res++;
		cc = 0;
		len--;
	}
	return (NULL);
}
