/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:11:05 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/02 18:17:00 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_get(char *str, int n)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)n)
			return ((char *)str + i);
		i++;
	}
	if (str == '\0' && n == 0)
		return ((char *)str + 1);
	return (NULL);
}

char	*ft_strjoin(const char *src, const char *dst)
{
	char	*result;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	result = malloc(sizeof(char) * (ft_strlen(src) + ft_strlen(dst) + 1));
	if (!result)
		return (NULL);
	while (src[i] != '\0')
	{
		result[i] = src[i];
		i++;
	}
	while (dst[y] != '\0')
	{
		result[i] = dst[y];
		i++;
		y++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	char	*newstring;

	i = 0;
	if (!(newstring = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i] != '\0')
	{
		newstring[i] = str[i];
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}

char	*ft_substr_get(char *str, size_t start, size_t len)
{
	char			*substring;
	unsigned int	slen;
	size_t			i;
	size_t			y;

	i = start;
	y = 0;
	if (!str)
		return (NULL);
	slen = ft_strlen(str);
	if (!(substring = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (start < slen)
	{
		while (i < (start + len) && str[i] != '\0')
		{
			substring[y] = str[i];
			i++;
			y++;
		}
		break ;
	}
	substring[y] = '\0';
	return (substring);
}
