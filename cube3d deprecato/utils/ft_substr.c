/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:58:03 by bde-luca          #+#    #+#             */
/*   Updated: 2021/01/20 11:03:21 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	size_t			i;
	size_t			y;
	unsigned int	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (!(substr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = start;
	y = 0;
	if (start < slen)
	{
		while (i < start + len && s[i] != '\0')
		{
			substr[y] = s[i];
			y++;
			i++;
		}
	}
	substr[y] = '\0';
	return (substr);
}
