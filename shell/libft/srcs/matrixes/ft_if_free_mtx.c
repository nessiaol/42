/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_free_mtx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 16:19:38 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/12 18:31:05 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_if_free_mtx(char ***m)
{
	int	i;

	i = 0;
	if (!(*m))
		return ;
	while ((*m)[i])
		ft_if_free((void **)&(*m)[i++]);
	ft_if_free((void **)&(*m));
}
