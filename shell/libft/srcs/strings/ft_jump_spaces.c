/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cserapon  <cserapon@student.42roma.it>     +#+  +:+       +#+        */
/*   &&: ppunzo    <ppunzo@student.42roma.it>     +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:41:07 by cserapon          #+#    #+#             */
/*   Updated: 2021/04/14 16:41:16 by cserapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_jump_spaces(char *line, int *i)
{
	++(*i);
	while (line && line[*i] && ft_isspace(line[*i]))
		++(*i);
	return (1);
}
