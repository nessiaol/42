/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stribuzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:43:49 by stribuzi          #+#    #+#             */
/*   Updated: 2021/03/30 17:51:03 by stribuzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	free_support(t_data *p)
{
	if (p->sprite_texture != NULL)
		free(p->sprite_texture);
	if (p->map != NULL)
		free(p->map);
	if (p->z_buffer != NULL)
		free(p->z_buffer);
	if (p->sprites != NULL)
		free(p->sprites);
	if (p->sprite_distance != NULL)
		free(p->sprite_distance);
	if (p->sprite_order != NULL)
		free(p->sprite_order);
}

void	free_program(t_data *p)
{
	if (p->mlx != NULL)
	{
		if (p->img != NULL)
			mlx_destroy_image(p->mlx, p->img);
		mlx_destroy_window(p->mlx, p->window);
	}
	if (p->north_texture != NULL)
		free(p->north_texture);
	if (p->south_texture != NULL)
		free(p->south_texture);
	if (p->east_texture != NULL)
		free(p->east_texture);
	if (p->west_texture != NULL)
		free(p->west_texture);
	free_support(p);
	system("killall afplay");
}

void	throw_error(t_data *p, char *error)
{
	free_program(p);
	printf("Error\n");
	system("tput setaf 9;");
	printf("%s", error);
	exit(0);
}

void	red_button(t_data *p)
{
	free_program(p);
	system("tput setaf 2; echo 'Ciao Anatra'");
	system("say -v Ciao Anatra");
	exit(0);
}

int	close_program(t_data *p)
{
	red_button(p);
	return (0);
}
