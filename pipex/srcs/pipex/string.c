/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:15:10 by bde-luca          #+#    #+#             */
/*   Updated: 2021/07/05 19:26:34 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

char	*ft_strtoupper(char *str)
{
	char	*tmp;
	int		i;

	tmp = ft_strnew(ft_strlen(str));
	i = 0;
	while (*str)
	{
		tmp[i] = ft_toupper(*str);
		str++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = (char*)ft_memalloc((size + 1) * sizeof(char));
	return (ptr);
}