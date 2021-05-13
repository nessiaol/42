/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmangola <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:27:25 by dmangola          #+#    #+#             */
/*   Updated: 2021/01/16 15:27:27 by dmangola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*str;
	unsigned char	m;
	unsigned int	i;

	str = (char *)b;
	m = (unsigned char)c;
	i = 0;
	while (i < len)
		str[i++] = m;
	return (b);
}
