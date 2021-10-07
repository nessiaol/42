/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 18:12:53 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/18 18:57:17 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_is_in_cset(char c, char *charset)
{
	int	index;

	index = 0;
	while (charset[index])
	{
		if (c == charset[index])
			return (1);
		index += 1;
	}
	return (0);
}

static int	ft_count_strs(char *line, int len, int i)
{
	int	n;

	n = 1;
	while (i < len)
	{
		if (line[i])
		{
			++n;
			while (line[i])
				++i;
		}
		else
			++i;
	}
	return (n);
}

static char	*ft_separate_strs(char *line, char *charset)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)ft_calloc(ft_strlen(line) + 1, sizeof(char));
	while (line[i])
	{
		if (ft_is_in_cset(line[i], charset))
			new[i] = 0;
		else
			new[i] = line[i];
		i++;
	}
	return (new);
}

char	**ft_split(char *line, char *charset)
{
	char	**splitted;
	int		i;
	int		j;
	int		len;

	len = ft_strlen(line);
	line = ft_separate_strs(line, charset);
	splitted = (char **)ft_calloc(ft_count_strs(line, len, 0), sizeof(char *));
	i = 0;
	j = 0;
	while (i < len)
	{
		if (line[i])
		{
			splitted[j] = ft_strdup(line + i);
			++j;
			while (line[i])
				++i;
		}
		else
			++i;
	}
	ft_if_free((void **)&line);
	return (splitted);
}
