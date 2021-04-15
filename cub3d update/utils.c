/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:23:41 by stribuzi          #+#    #+#             */
/*   Updated: 2021/04/14 19:12:56 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

int	is_sprite(char c)
{
	if (c == '2')
		return (1);
	return (0);
}

int	is_spawn_position(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	is_printable(int c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}
