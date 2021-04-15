/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_prova.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:28:51 by dseptar           #+#    #+#             */
/*   Updated: 2021/04/14 19:42:16 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "parser.h"

int close_program_x(t_data *data)
{
	printf("Ciao Anatra");
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	system("killall afplay");
	exit(0);
}

int	init_move_press(int keycode, t_data *img)
{
	if (keycode == 13)
		img->keycode.key_w = 1;
	if (keycode == 1)
		img->keycode.key_s = 1;
	if (keycode == 123)	
		img->keycode.key_fs = 1;
	if (keycode == 124)
		img->keycode.key_fd = 1;
	if (keycode == 0)
		img->keycode.key_a = 1;
	if (keycode == 2)
		img->keycode.key_d = 1;
	if (keycode == 53)
		img->keycode.key_esc = 1;
	return (0);
}

int	init_move_release(int keycode, t_data *img)
{
	if (keycode == 13)
		img->keycode.key_w = 0;
	if (keycode == 1)
		img->keycode.key_s = 0;
	if (keycode == 123)	
		img->keycode.key_fs = 0;
	if (keycode == 124)
		img->keycode.key_fd = 0;
	if (keycode == 0)
		img->keycode.key_a = 0;
	if (keycode == 2)
		img->keycode.key_d = 0;
	if (keycode == 53)
		img->keycode.key_esc = 0;
	return (0);
}

void init_movement_start(t_data *img)
{
	img->keycode.key_w = 0;
	img->keycode.key_s = 0;
	img->keycode.key_fs = 0;
	img->keycode.key_fd = 0;
	img->keycode.key_a = 0;
	img->keycode.key_d = 0;
	img->keycode.key_esc = 0;
	img->sprite_count = 0;
	img->initial_num_sprite = img->num_sprite;
	img->end_game = 0;
}

///// CALCOLA MOVIMENTO LATERALE /////
void	move_d(t_data *data)
{
	double	dirx;
	double	diry;
	double	old_dirx;
	double	old_diry;

	old_dirx = data->player.dirx;
	old_diry = data->player.diry;

	double roatation_speed = ft_deg_to_rad(90);
	double move_speed = 0.3;
	dirx = data->player.dirx * cos(-roatation_speed) - data->player.diry * sin(-roatation_speed);
	diry = old_dirx * sin(-roatation_speed) + data->player.diry * cos(-roatation_speed);

	if (is_wall(data->map[(int)(data->player.posx - dirx * move_speed)][(int)(data->player.posy)]) == 0)
			data->player.posx += dirx * move_speed;
	if (is_wall(data->map[(int)(data->player.posx)][(int)(data->player.posy + diry * move_speed)]) == 0)
			data->player.posy += diry * move_speed;
}

void	move_s(t_data *data)
{
	double	dirx;
	double	diry;
	double	old_dirx;
	double	old_diry;

	old_dirx = data->player.dirx;
	old_diry = data->player.diry;

	double roatation_speed = ft_deg_to_rad(90);
	double move_speed = 0.3;
	dirx = data->player.dirx * cos(-roatation_speed) - data->player.diry * sin(-roatation_speed);
	diry = old_dirx * sin(-roatation_speed) + data->player.diry * cos(-roatation_speed);

	if (is_wall(data->map[(int)(data->player.posx - dirx * move_speed)][(int)(data->player.posy)]) == 0 )
		data->player.posx -= dirx * move_speed;
	if (is_wall(data->map[(int)(data->player.posx)][(int)(data->player.posy + diry * move_speed)]) == 0)
		data->player.posy -= diry * move_speed;
}
///// ROTAZIONE VISUALE COL MOUSE /////
int	move_mouse(int x, int y, t_data *data)
{
	static	int tmp;
	if (tmp == x || (x >= (tmp - 5) && x <= (tmp + 5)))
	{
		data->keycode.key_fs = 0;
		data->keycode.key_fd = 0;
		return 0;
	}

	if (tmp > x)
	{
		//Ruota a sinistra
		data->keycode.key_fs = 1;
		data->keycode.key_fd = 0;

	}
	else
	{
		//Ruota a destra
		data->keycode.key_fs = 0;
		data->keycode.key_fd = 1;
	}
	tmp = x;
	return (1);
}

int	move_and_close(t_data *data)
{
	double	move_speed;
	double 	roatation_speed;
	double	old_dirx;
	double	old_planex;

	move_speed = 0.3;
	roatation_speed = ft_deg_to_rad(3);
	old_dirx = data->player.dirx;
	old_planex = data->player.planex;
	ft_count_sprite_game(data);
	if (data->keycode.key_w == 1) //AVANZARE SU (W)
	{
		if (is_wall(data->map[(int)(data->player.posx + data->player.dirx * move_speed)][(int)(data->player.posy)]) == 0)
			data->player.posx += data->player.dirx * move_speed;
		if (is_wall(data->map[(int)(data->player.posx)][(int)(data->player.posy + data->player.diry * move_speed)]) == 0)
			data->player.posy += data->player.diry * move_speed;
	}
	if (data->keycode.key_s == 1) //AVANZARE GIÚ (S)
	{
		if (is_wall(data->map[(int)(data->player.posx - data->player.dirx * move_speed)][(int)(data->player.posy)]) == 0)
			data->player.posx -= data->player.dirx * move_speed;
		if (is_wall(data->map[(int)(data->player.posx)][(int)(data->player.posy + data->player.diry * move_speed)]) == 0)
			data->player.posy -= data->player.diry * move_speed;
	}
	if (data->keycode.key_a == 1) //AVANZARE SINISTRA (A)
	{
		move_s(data);
	}
	if (data->keycode.key_d == 1) //AVANZARE DESTRA (D)
	{
		move_d(data);
	}
	if (data->keycode.key_fd == 1) //RUOTARE A DESTRA (->)
	{
		data->player.dirx = data->player.dirx * cos(-roatation_speed) - data->player.diry * sin(-roatation_speed);
		data->player.diry = old_dirx * sin(-roatation_speed) + data->player.diry * cos(-roatation_speed);
		data->player.planex = data->player.planex * cos(-roatation_speed) - data->player.planey * sin(-roatation_speed);
		data->player.planey = old_planex * sin(-roatation_speed) + data->player.planey * cos(-roatation_speed);
	}
	if (data->keycode.key_fs == 1) //RUOTARE A SINISTRA (<-)
	{
		data->player.dirx = data->player.dirx * cos(roatation_speed) - data->player.diry * sin(roatation_speed);
		data->player.diry = old_dirx * sin(roatation_speed) + data->player.diry * cos(roatation_speed);
		data->player.planex = data->player.planex * cos(roatation_speed) - data->player.planey * sin(roatation_speed);
		data->player.planey = old_planex * sin(roatation_speed) + data->player.planey * cos(roatation_speed);
	}
	if (data->keycode.key_esc == 1)
	{
		printf("Ciao Anatra");
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->mlx_win);
		system("killall afplay");
		exit(0);
	}
	return (0);
}

void	ver_line(t_data *data, int x, int draw_start, int draw_end, int color_pixel)
{
	while (draw_start < draw_end)
	{
		my_mlx_pixel_put(data, x, draw_start, color_pixel);
		draw_start++;
	}
}
///// STAMPARE A SCHERMO CIELO E TERRA CON TEXTURE /////
void	to_print_txt_c_t(t_data *data)
{
	t_color color;
	int		y;
	int		x;
	int		p;
	int		cell_x;
	int		cell_y;
	int		tex_x;
	int		tex_y;
	int		color_pixel_floor;
	int		color_pixel_sky;
	float	ray_dirx_0;
	float	ray_diry_0;
	float	ray_dirx_1;
	float	ray_diry_1;
	float	pos_z;
	float	row_distance;
	float	floor_x;
	float	floor_y;
	float	floor_step_x;
	float	floor_step_y;

	y = 0;
	while (y < data->screen_height)
	{
		ray_dirx_0 = data->player.dirx - data->player.planex;
		ray_diry_0 = data->player.diry - data->player.planey;
		ray_dirx_1 = data->player.dirx + data->player.planex;
		ray_diry_1 = data->player.diry + data->player.planey;
		p = y - data->screen_height / 2;
		pos_z = 0.5 * data->screen_height;
		row_distance = pos_z / p;
		floor_step_x = row_distance * (ray_dirx_1 - ray_dirx_0) / data->screen_width;
		floor_step_y = row_distance * (ray_diry_1 - ray_diry_0) / data->screen_width;
		floor_x = data->player.posx + row_distance * ray_dirx_0;
		floor_y = data->player.posy + row_distance * ray_diry_0;
		x = 0;
		while (x < data->screen_width)
		{
			cell_x = (int)(floor_x);
			cell_y = (int)(floor_y);
			tex_x = (int)(data->floor_txt.width * (floor_x - cell_x)) & (data->floor_txt.width - 1);
			tex_y = (int)(data->floor_txt.height * (floor_y - cell_y)) & (data->floor_txt.height - 1);
			floor_x += floor_step_x;
			floor_y += floor_step_y;
			color_pixel_floor = data->floor_txt.data[data->floor_txt.height * tex_x + tex_y];
			if (data->do_screenshot == 1)
			{
				color = ft_int_to_rgb(color_pixel_sky);
				data->position_screenshot = (y * data->screen_width + x) * 3;
				data->screenshot[data->position_screenshot] = color.b;
				data->screenshot[data->position_screenshot + 1] = color.g;
				data->screenshot[data->position_screenshot + 2] = color.r;
			}
			my_mlx_pixel_put(data, x, y, color_pixel_floor);
			color_pixel_sky = data->sky_txt.data[data->sky_txt.height * tex_x + tex_y];
			if (data->do_screenshot == 1)
			{
				color = ft_int_to_rgb(color_pixel_floor);
				data->position_screenshot = ((data->screen_height - y - 1) * data->screen_width + x) * 3;
				data->screenshot[data->position_screenshot] = color.b;
				data->screenshot[data->position_screenshot + 1] = color.g;
				data->screenshot[data->position_screenshot + 2] = color.r;
			}
			my_mlx_pixel_put(data, x, data->screen_height - y - 1, color_pixel_sky);
			x++;
		}
		y++;
	}
}
///// STAMPARE A SCHERMO LE TEXTURE /////
// void	to_sprite(t_data *data)
// {
// 	t_color color;
// 	int			sprite_order[data->num_sprite];
// 	double		sprite_distance[data->num_sprite];
// 	double 		sprite_x;
// 	double 		sprite_y;
// 	double 		inv_det;
// 	double 		transform_x;
// 	double 		transform_y;
// 	int 		draw_start_y;
// 	int 		draw_start_x;
// 	int 		draw_end_y;
// 	int 		draw_end_x;
// 	int 		stripe;
// 	int			d;
// 	int 		sprite_height;
// 	int 		sprite_width;
// 	int			i;
// 	int 		sprite_screen_x;
// 	int			tex_x;
// 	int			tex_y;
// 	int			color_pixel;
// 	int			y;

// 	i = 0;
// 	//ordina gli sprite da lontano a vicino
// 	while (i < data->num_sprite)
//     {
//       sprite_order[i] = i;
//       sprite_distance[i] = ((data->player.posx - data->sprites[i][0]) * (data->player.posx - data->sprites[i][0]) + \
// 	   (data->player.posy - data->sprites[i][1]) * (data->player.posy - data->sprites[i][1]));
// 	  i++;
//     }
// 	ft_sort(sprite_order, sprite_distance, data->num_sprite);
// 	ft_reverse(sprite_order, sprite_distance, data->num_sprite);
// 	i = 0;
//     //dopo aver ordinato gli sprite, esegui la proiezione e disegnali
//     while (i < data->num_sprite)
//     {
//       //traduci la posizione dello sprite in relativa alla camera
//       sprite_x = data->sprites[sprite_order[i]][0] - data->player.posx;
//       sprite_y = data->sprites[sprite_order[i]][1] - data->player.posy;
//       inv_det = 1.0 / (data->player.planex * data->player.diry - data->player.dirx * data->player.planey); //richiesto per la corretta moltiplicazione della matrice
//       transform_x = inv_det * (data->player.diry * sprite_x - data->player.dirx * sprite_y);
//       transform_y = inv_det * (-data->player.planey * sprite_x + data->player.planex * sprite_y); //questa è effettivamente la profondità all'interno dello schermo, ovvero ciò che Z è in 3D
//       sprite_screen_x = (int)((data->screen_width / 2) * (1 + transform_x / transform_y));
//       //calculate height of the sprite on screen
//       sprite_height = abs((int)(data->screen_height / (transform_y))); //l'uso di 'transformY' al posto della distanza reale impedisce il fisheye
//       //calcola il pixel più basso e più alto per riempire la striscia corrente
//       draw_start_y = -sprite_height / 2 + data->screen_height / 2;
//       if (draw_start_y < 0) draw_start_y = 0;
//       draw_end_y = sprite_height / 2 + data->screen_height / 2;
//       if (draw_end_y >= data->screen_height) draw_end_y = data->screen_height - 1;
//       //calcola la larghezza dello sprite
//       sprite_width = abs((int)(data->screen_height / (transform_y)));
//       draw_start_x = -sprite_width / 2 + sprite_screen_x;
//       if (draw_start_x < 0) draw_start_x = 0;
//       draw_end_x = sprite_width / 2 + sprite_screen_x;
//       if(draw_end_x >= data->screen_width) draw_end_x = data->screen_width - 1;
//       //scorre ogni striscia verticale dello sprite sullo schermo
// 	  stripe = draw_start_x;
//       while (stripe < draw_end_x)
//       {
//         tex_x = (int)(256 * (stripe - (-sprite_width / 2 + sprite_screen_x)) * data->sprite_1.width / sprite_width) / 256;
//         if (transform_y > 0 && stripe > 0 && stripe < data->screen_width && transform_y < data->z_buffer[stripe])
// 		{
// 			y = draw_start_y;
//         	while (y < draw_end_y)
//      		{
//           		d = (y) * 256 - data->screen_height * 128 + sprite_height * 128;
//           		tex_y = ((d * data->sprite_1.height) / sprite_height) / 256;
//           		color_pixel = data->sprite_1.data[data->sprite_1.height * tex_y + tex_x];
// 		  		if ((color_pixel & 0x00FFFFFF) != 0)
// 				{
// 					if (data->do_screenshot == 1)
// 					{
// 						color = ft_int_to_rgb(color_pixel);
// 						data->position_screenshot = (y * data->screen_width + stripe) * 3;
// 						data->screenshot[data->position_screenshot] = color.b;
// 						data->screenshot[data->position_screenshot + 1] = color.g;
// 						data->screenshot[data->position_screenshot + 2] = color.r;
// 					}
// 		  			my_mlx_pixel_put(data, stripe, y, (color_pixel));
// 				  }
// 				y++;
// 			}
//         }
// 		stripe++;
//       }
// 	  i++;
//     }
// }

///// STAMPARE A SCHERMO CIELO E TERRA SENZA TEXTURE /////
void	to_print_c_t(t_data *data)
{
	t_color color;
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < data->screen_height / 2)
	{
		x = 0;
		while (x < data->screen_width)
		{
			if (data->do_screenshot == 1)
			{
				color = ft_int_to_rgb(data->ceiling_color);
				data->position_screenshot = (y * data->screen_width + x) * 3;
				data->screenshot[data->position_screenshot] = color.b;
				data->screenshot[data->position_screenshot + 1] = color.g;
				data->screenshot[data->position_screenshot + 2] = color.r;
			}
			my_mlx_pixel_put(data, x, y, data->ceiling_color);
			x++;
		}
		y++; 
	}
	y = data->screen_height / 2;
	while (y < data->screen_height)
	{
		x = 0;
		while (x < data->screen_width)
		{
			if (data->do_screenshot == 1)
			{
				color = ft_int_to_rgb(data->floor_color);
				data->position_screenshot = (y * data->screen_width + x) * 3;
				data->screenshot[data->position_screenshot] = color.b;
				data->screenshot[data->position_screenshot + 1] = color.g;
				data->screenshot[data->position_screenshot + 2] = color.r;
			}
			my_mlx_pixel_put(data, x, y, data->floor_color);
			x++;
		}
		y++; 
	}
}
///// IMMAGINE FINALE /////
void		render_end(t_data *data)
{
	int	y;
	int x;
	int	rx;
	int	ry;
	int	color_pixel;

	y = 0;
	while (y < data->screen_height)
	{
		x = 0;
		while (x < data->screen_width)
		{
			rx = floor((x - (int)(data->screen_width * 0)) * 1920 / (data->screen_width * 1));
			ry = floor((y - (int)(data->screen_height * 0)) * 1080 / (data->screen_height * 1));
			color_pixel = (int)(data->end.data[data->end.width * ry + rx]);
			my_mlx_pixel_put(data, x, y, color_pixel);
			x++;
		}
		y++;
	}
}
///// RAYCASTING /////
int		render_next_frame(t_data *img)
{
	t_color color;
	int		x;
	int		y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color_pixel;
	int		tex_x;
	int		tex_y;
	char	count_sprite[4];
	double	side_distx;
	double	side_disty;
	double	ray_dirx;
	double	ray_diry;
	double	perp_wall_dist;
	double 	camerax;
	double	delta_distx;
	double	delta_disty;
	double	wall_x;
	double	step;
	double	tex_pos;


	count_sprite[0] = img->sprite_count + '0';
	count_sprite[1] = '/';
	count_sprite[2] = img->initial_num_sprite + '0';
	count_sprite[3] = '\0';
	if (img->end_game == 1)
	{
		img->end.img = mlx_png_file_to_image(img->mlx, "textures/txt/THE_END.png", &img->end.width, &img->end.height);
		img->end.data = (unsigned int *)mlx_get_data_addr(img->end.img, &img->end.bits_per_pixel, &img->end.line_length, &img->end.endian);
		render_end(img);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
		move_and_close(img);
		return (0);
	}
	if (img->do_screenshot == 1)
	{
		img->screenshot = malloc(sizeof(unsigned char) * img->screen_height * img->screen_width * 4);
		if (!img->screenshot)
			throw_error(img, "Malloc failed\n");
	}
	x = 0;
	//to_print_c_t(img);
	to_print_txt_c_t(img);
	while (x < img->screen_width)
	{
		///// POSIZIONARE IL PLAYER /////
		camerax = ((2 * x) / (double)img->screen_width) - 1;
		ray_dirx = img->player.dirx + (img->player.planex * camerax);
		ray_diry = img->player.diry + (img->player.planey * camerax);
		map_x = (int)img->player.posx;
		map_y = (int)img->player.posy;
		if (ray_diry == 0)
			delta_distx = 0;
		else if (ray_dirx == 0)
			delta_distx = 1;
		else
			delta_distx = fabs(1 / ray_dirx);
		if (ray_dirx == 0)
			delta_disty = 0;
		else if (ray_diry == 0)
			delta_disty = 1;
		else
			delta_disty = fabs(1 / ray_diry);
		if (ray_dirx < 0)
		{
			step_x = -1;
			side_distx = (img->player.posx - map_x) * delta_distx;
		}
		else
		{
			step_x = 1;
			side_distx = ((map_x + 1.0) - img->player.posx) * delta_distx;
		}
		if (ray_diry < 0)
		{
			step_y = -1;
			side_disty = (img->player.posy - map_y) * delta_disty;
		}
		else
		{
			step_y = 1;
			side_disty = ((map_y + 1.0 - img->player.posy) * delta_disty);
		}
		///// DDA PER TROVARE QUANDO COLPISCI UN MURO /////
		hit = 0;
		while (hit == 0)
		{
			if (side_distx < side_disty)
			{
				side_distx += delta_distx;
				map_x += step_x;
				img->side = 0;
				if (step_x == -1)
					img->side = 2;
			}
			else
			{
				side_disty += delta_disty;
				map_y += step_y;
				img->side = 1;
				if (step_y == -1)
				img->side = 3;
			}
			if (img->map[map_x][map_y] != '0' && img->map[map_x][map_y] != '2' && img->map[map_x][map_y] != 'N' && img->map[map_x][map_y] != 'S' && img->map[map_x][map_y] != 'W' && img->map[map_x][map_y] != 'E')
				hit = 1;
		}
		///// CALCOLA DISTANZA TRA PLAYER E IL MURO COLPITO /////
		if (img->side == 0 || img->side == 2)
			perp_wall_dist = ((map_x - img->player.posx + (1 - step_x) / 2) / ray_dirx);
		else
			perp_wall_dist = ((map_y - img->player.posy + (1 - step_y) / 2) / ray_diry);
		///// CALCOLA ALTEZZA DELLA LINEA DA DISEGNARE SULLO SCHERMO /////
		line_height = (int)(img->screen_height / perp_wall_dist); //Calcola l'altezza della linea da disegnare sullo schermo. h é uguale all'altezza dello schermo
		draw_start = (-line_height / 2) + (img->screen_height / 2); //draw_start  e draw_end calcola il pixel più basso e più alto per riempire la striscia corrente
		if (draw_start < 0)
			draw_start = 0;
		draw_end = (line_height / 2) + (img->screen_height / 2);
		if (draw_end >= img->screen_height)
			draw_end = img->screen_height - 1;
		///// INSERIMENTO TEXTURE /////
		if (img->side == 0 || img->side == 2) //Calcola il valore di wallX
			wall_x = img->player.posy + perp_wall_dist * ray_diry;
		else
			wall_x = img->player.posx + perp_wall_dist * ray_dirx;
		wall_x -= floor((wall_x));
		tex_x = (int)(wall_x * img->nord_txt.width); //Coordinata x sulla texture
		if (img->side == 0 && ray_dirx > 0)
			tex_x = img->nord_txt.width - tex_x - 1;
		if (img->side == 1 && ray_diry < 0)
			tex_x = img->sud_txt.width - tex_x - 1;
		if (img->side == 2 && ray_diry < 0)
			tex_x = img->est_txt.width - tex_x - 1;
		if (img->side == 3 && ray_diry < 0)
			tex_x = img->ovest_txt.width - tex_x - 1;
		step = 1.0 * img->nord_txt.height / line_height; //Quanto aumentare la coordinata della texture per ogni pixel dello schermo
		tex_pos = (draw_start - img->screen_height / 2 + line_height / 2) * step;
		y = draw_start;
		while (y < draw_end)
		{
			tex_y = (int)tex_pos & (img->nord_txt.height - 1);
			tex_pos += step;
			if (img->side == 0)
				color_pixel = img->nord_txt.data[img->nord_txt.height * tex_y + tex_x];
			if (img->side == 1)
				color_pixel = img->sud_txt.data[img->sud_txt.height * tex_y + tex_x];
			if (img->side == 2)
				color_pixel = img->est_txt.data[img->est_txt.height * tex_y + tex_x];
			if (img->side == 3)
				color_pixel = img->ovest_txt.data[img->ovest_txt.height * tex_y + tex_x];
			if (img->side == 1 || img->side == 3)
				color_pixel = (color_pixel >> 1) & 8355711; //Rende il colore più scuro per i lati y: R, G e B byte ciascuno diviso per due
			if (img->do_screenshot == 1)
			{
				color = ft_int_to_rgb(color_pixel);
				img->position_screenshot = (y * img->screen_width + x) * 3;
				img->screenshot[img->position_screenshot] = color.b;
				img->screenshot[img->position_screenshot + 1] = color.g;
				img->screenshot[img->position_screenshot + 2] = color.r;
			}
			my_mlx_pixel_put(img, x, y, color_pixel);
			y++;
		}
		img->z_buffer[x] = perp_wall_dist;
		x++;
	}
	to_sprite(img);
	if (img->do_screenshot == 1)
	{
		write_screenshot(img, img->screenshot);
		exit(1);
	}
	move_and_close(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_string_put(img->mlx, img->mlx_win, img->screen_width * 0.1, img->screen_height * 0.1, 0x00FF0000, count_sprite);
	//ft_lifebar(img);
	mlx_do_sync(img->mlx);
	return (0);
}

///// CARICAMENTO TEXTURE /////
void		load_texture(t_data *data)
{
	if (ft_strcmp(&data->north_texture[ft_strlen(data->north_texture) - 4], ".xpm") == 0)
		data->nord_txt.img = mlx_xpm_file_to_image(data->mlx, data->north_texture, &data->nord_txt.width, &data->nord_txt.height);
	else
		data->nord_txt.img = mlx_png_file_to_image(data->mlx, data->north_texture, &data->nord_txt.width, &data->nord_txt.height);
	data->nord_txt.data = (unsigned int *)mlx_get_data_addr(data->nord_txt.img, &data->nord_txt.bits_per_pixel, &data->nord_txt.line_length, &data->nord_txt.endian);

	if (ft_strcmp(&data->south_texture[ft_strlen(data->south_texture) - 4], ".xpm") == 0)
		data->sud_txt.img = mlx_xpm_file_to_image(data->mlx, data->south_texture, &data->sud_txt.width, &data->sud_txt.height);
	else
		data->sud_txt.img = mlx_png_file_to_image(data->mlx, data->south_texture, &data->sud_txt.width, &data->sud_txt.height);
	data->sud_txt.data = (unsigned int *)mlx_get_data_addr(data->sud_txt.img, &data->sud_txt.bits_per_pixel, &data->sud_txt.line_length, &data->sud_txt.endian);

	if (ft_strcmp(&data->east_texture[ft_strlen(data->east_texture) - 4], ".xpm") == 0)
		data->est_txt.img = mlx_xpm_file_to_image(data->mlx, data->east_texture, &data->est_txt.width, &data->est_txt.height);
	else
		data->est_txt.img = mlx_png_file_to_image(data->mlx, data->east_texture, &data->est_txt.width, &data->est_txt.height);
	data->est_txt.data = (unsigned int *)mlx_get_data_addr(data->est_txt.img, &data->est_txt.bits_per_pixel, &data->est_txt.line_length, &data->est_txt.endian);

	if (ft_strcmp(&data->west_texture[ft_strlen(data->west_texture) - 4], ".xpm") == 0)
		data->ovest_txt.img = mlx_xpm_file_to_image(data->mlx, data->west_texture, &data->ovest_txt.width, &data->ovest_txt.height);
	else
		data->ovest_txt.img = mlx_png_file_to_image(data->mlx, data->west_texture, &data->ovest_txt.width, &data->ovest_txt.height);
	data->ovest_txt.data = (unsigned int *)mlx_get_data_addr(data->ovest_txt.img, &data->ovest_txt.bits_per_pixel, &data->ovest_txt.line_length, &data->ovest_txt.endian);

	data->floor_txt.img = mlx_xpm_file_to_image(data->mlx, "textures/txt/sol_neon.xpm", &data->floor_txt.width, &data->floor_txt.height);
	data->floor_txt.data = (unsigned int *)mlx_get_data_addr(data->floor_txt.img, &data->floor_txt.bits_per_pixel, &data->floor_txt.line_length, &data->floor_txt.endian);

	data->sky_txt.img = mlx_xpm_file_to_image(data->mlx, "textures/txt/wall-1.xpm", &data->sky_txt.width, &data->sky_txt.height);
	data->sky_txt.data = (unsigned int *)mlx_get_data_addr(data->sky_txt.img, &data->sky_txt.bits_per_pixel, &data->sky_txt.line_length, &data->sky_txt.endian);
	
	//data->sprite.img = mlx_png_file_to_image(data->mlx, "textures/txt/pillar.png", &data->sprite.width, &data->sprite.height);
	//data->sprite.data = (unsigned int *)mlx_get_data_addr(data->sprite.img, &data->sprite.bits_per_pixel, &data->sprite.line_length, &data->sprite.endian);

	if (ft_strcmp(&data->sprite_texture[ft_strlen(data->sprite_texture) - 4], ".xpm") == 0)
		data->sprite_1.img = mlx_xpm_file_to_image(data->mlx, data->sprite_texture, &data->sprite_1.width, &data->sprite_1.height);
	else
		data->sprite_1.img = mlx_png_file_to_image(data->mlx, data->sprite_texture, &data->sprite_1.width, &data->sprite_1.height);
	data->sprite_1.data = (unsigned int *)mlx_get_data_addr(data->sprite_1.img, &data->sprite_1.bits_per_pixel, &data->sprite_1.line_length, &data->sprite_1.endian);
}



void	init_game(t_data *img)
{
	img->mlx = mlx_init();
    img->mlx_win = mlx_new_window(img->mlx, img->screen_width, img->screen_height, "TRONIX");
    img->img = mlx_new_image(img->mlx, img->screen_width, img->screen_height);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	img->player = init_player(img->player);
	load_texture(img);
	mlx_hook(img->mlx_win, 17, 1L<<0, close_program_x, img);
	init_movement_start(img);
	mlx_hook(img->mlx_win, 2, 1L<<0, init_move_press, img);
	mlx_hook(img->mlx_win, 3, 1L<<1, init_move_release, img);
	mlx_hook(img->mlx_win, 06, 1L<<6, move_mouse, img);
	mlx_loop_hook(img->mlx, render_next_frame, img);
	mlx_loop(img->mlx);
}

int		main(int argc, char **argv)
{
    t_data  p;
	ft_init_movement(&p);
	if (argc == 2 && ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub") == 0)
	{
		system("say -v Samantha Welcome to Tronix; afplay tron.mp3 &");
		parse_info(argv[1], &p);
		p.do_screenshot = 0;
		init_game(&p);
	}
	else if (argc == 3 && (ft_strcmp(argv[2], "--save") == 0)
		&& ft_strcmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub") == 0)
	{
		system("afplay tron.mp3 &");
		parse_info(argv[1], &p);
		p.do_screenshot = 1;
		init_game(&p);
	}
	else
	{
		system("say -v Samantha Put a valid map, idiot! &");
		system("afplay tron.mp3 &");
		throw_error(&p, "Invalid options");
		exit(0);
	}
	return (0);
}