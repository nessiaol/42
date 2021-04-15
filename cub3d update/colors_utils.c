/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 08:02:50 by stribuzi          #+#    #+#             */
/*   Updated: 2021/04/14 18:40:56 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ft_color_to_int(int red, int green, int blue)
{
	int		rgb;

	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}

t_color	ft_int_to_rgb(int color)
{
	int		b;
	int		g;
	int		r;
	t_color	to_return;

	b = color % 256;
	g = ((color - b) / 256) % 256;
	r = ((color - b) / pow(256, 2)) - g / 256;
	to_return.r = r;
	to_return.g = g;
	to_return.b = b;
	return (to_return);
}
