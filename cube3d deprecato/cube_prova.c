/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpova_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseptar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 12:28:51 by dseptar           #+#    #+#             */
/*   Updated: 2021/03/17 12:28:53 by dseptar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define mapWidth 24 
#define mapHeight 24
#define TRUE 1
#define FALSE 0

#define screen_width 1920
#define screen_height 1080

int worldmap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

typedef struct 	s_keycode 
{
	int			key_w;
	int			key_a;
	int			key_s;
	int			key_d;
	int			key_fd;
	int			key_fs;
	int			key_esc;
}				t_keycode;


typedef	struct  	s_texture
{
	void			*img;
	unsigned int 	*data;
	int				bits_per_pixel;
    int				line_length;
    int				endian;
	int				width;
	int				height;
}				t_texture;

typedef struct 	s_player 
{
	double 		posx;
	double		posy;
  	double 		dirx;
	double		diry;
  	double 		planex;
	double		planey;
}				t_player;

typedef struct	s_data 
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
    int			line_length;
    int			endian;
	int			num_sprite;
	int			**sprites;
	double		*z_buffer;
	void		*mlx;
	void		*mlx_win;
	t_player	player;
	t_texture	nord_txt;
	t_texture	floor_txt;
	t_texture	sky_txt;
	t_texture	sprite;
	t_keycode	keycode;
}				t_data;

float deg_to_rad(int deg) //Funzione conversione da gradi a radianti
{
	float rad;

	rad = deg * M_PI / 180;
	return (rad);
}

int		conv_color_pixel(int red, int green, int blue)
{
	int rgb;

	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int close_program_x(t_data *data)
{
	printf("Ciao Anatra");
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
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
///// CALCOLA MOVIMENTO LATERALE /////
void	move_d(t_data *data)
{
	double	dirx;
	double	diry;
	double	old_dirx;
	double	old_diry;

	old_dirx = data->player.dirx;
	old_diry = data->player.diry;

	double roatation_speed = deg_to_rad(90);
	double move_speed = 0.3;
	dirx = data->player.dirx * cos(-roatation_speed) - data->player.diry * sin(-roatation_speed);
	diry = old_dirx * sin(-roatation_speed) + data->player.diry * cos(-roatation_speed);

	if (worldmap[(int)(data->player.posx - dirx * move_speed)][(int)(data->player.posy)] == FALSE)
			data->player.posx += dirx * move_speed;
	if (worldmap[(int)(data->player.posx)][(int)(data->player.posy + diry * move_speed)] == FALSE)
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

	double roatation_speed = deg_to_rad(90);
	double move_speed = 0.3;
	dirx = data->player.dirx * cos(-roatation_speed) - data->player.diry * sin(-roatation_speed);
	diry = old_dirx * sin(-roatation_speed) + data->player.diry * cos(-roatation_speed);

	if (worldmap[(int)(data->player.posx - dirx * move_speed)][(int)(data->player.posy)] == FALSE)
		data->player.posx -= dirx * move_speed;
	if (worldmap[(int)(data->player.posx)][(int)(data->player.posy + diry * move_speed)] == FALSE)
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
///// CALCOLA MOVIMENTI E ROTAZIONE PERSONAGGIO /////
int	move_and_close(t_data *data)
{
	double	move_speed;
	double 	roatation_speed;
	double	old_dirx;
	double	old_planex;

	move_speed = 0.3;
	roatation_speed = deg_to_rad(3);
	old_dirx = data->player.dirx;
	old_planex = data->player.planex;
	if (data->keycode.key_w == 1) //AVANZARE SU (W)
	{
		if (worldmap[(int)(data->player.posx + data->player.dirx * move_speed)][(int)(data->player.posy)] == FALSE)
			data->player.posx += data->player.dirx * move_speed;
		if (worldmap[(int)(data->player.posx)][(int)(data->player.posy + data->player.diry * move_speed)] == FALSE)
			data->player.posy += data->player.diry * move_speed;
	}
	if (data->keycode.key_s == 1) //AVANZARE GIÚ (S)
	{
		if (worldmap[(int)(data->player.posx - data->player.dirx * move_speed)][(int)(data->player.posy)] == FALSE)
			data->player.posx -= data->player.dirx * move_speed;
		if (worldmap[(int)(data->player.posx)][(int)(data->player.posy + data->player.diry * move_speed)] == FALSE)
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
		exit(0);
	}
	return (0);
}

t_player	init_player(t_player player)
{
	player.posx = 22;
	player.posy = 12;
  	player.dirx = -1;
	player.diry = 0;
  	player.planex = 0;
	player.planey = 0.66;
  	return (player);
}

void	init_sprite(t_data *data)
{
	int i;

	i  = 0;
	data->num_sprite = 2;
	data->sprites = malloc(sizeof (int *) * data->num_sprite);
	data->z_buffer = malloc(sizeof (double) * screen_width);
	while (i < data->num_sprite)
	{
		data->sprites[i] = malloc(sizeof (int) * 2);
		i++;
	}
	data->sprites[0][0] = 3;
	data->sprites[0][1] = 3;
	data->sprites[1][0] = 6;
	data->sprites[1][1] = 6;
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
	int		y;
	int		x;
	int		h;
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
	h = screen_height;
	while (y < h)
	{
		ray_dirx_0 = data->player.dirx - data->player.planex;
		ray_diry_0 = data->player.diry - data->player.planey;
		ray_dirx_1 = data->player.dirx + data->player.planex;
		ray_diry_1 = data->player.diry + data->player.planey;
		p = y - screen_height / 2;
		pos_z = 0.5 * screen_height;
		row_distance = pos_z / p;
		floor_step_x = row_distance * (ray_dirx_1 - ray_dirx_0) / screen_width;
		floor_step_y = row_distance * (ray_diry_1 - ray_diry_0) / screen_width;
		floor_x = data->player.posx + row_distance * ray_dirx_0;
		floor_y = data->player.posy + row_distance * ray_diry_0;
		x = 0;
		while (x < screen_width)
		{
			cell_x = (int)(floor_x);
			cell_y = (int)(floor_y);
			tex_x = (int)(data->floor_txt.width * (floor_x - cell_x)) & (data->floor_txt.width - 1);
			tex_y = (int)(data->floor_txt.height * (floor_y - cell_y)) & (data->floor_txt.height - 1);
			floor_x += floor_step_x;
			floor_y += floor_step_y;
			color_pixel_floor = data->floor_txt.data[data->floor_txt.height * tex_x + tex_y];
			my_mlx_pixel_put(data, x, y, color_pixel_floor);
			color_pixel_sky = data->sky_txt.data[data->sky_txt.height * tex_x + tex_y];
			my_mlx_pixel_put(data, x, screen_height - y - 1, color_pixel_sky);
			x++;
		}
		y++;
	}
}

void	to_sprite(t_data *data)
{
	int 	i;
	int		stripe;
	int		tex_x;
	int		tex_y;
	int		sprite_order[data->num_sprite];
	int		sprite_screeen_x;
	int		sprite_height;
	int		sprite_width;
	int		draw_start_y;
	int		draw_end_y;
	int		draw_start_x;
	int		draw_end_x;
	int		d;
	int		y;
	int		color_pixel;
	double	sprite_distance[data->num_sprite];
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	trasfmor_x;
	double	trasfmor_y;

	i = 0;
	//ordina gli sprite dal più lontano al più vicino
	
	while (i < data->num_sprite)
	{
		sprite_order[i] = i;
		sprite_distance[i] = ((data->player.posx - data->sprites[i][0]) + (data->player.posy - data->sprites[i][1]) * (data->player.posy - data->sprites[i][1]));
		i++;
	}
	i = 0;
	while (i < 2)
	{
		//identifica la posizione della sprite relativa alla camera
		sprite_x = (data->sprites[i][0] - data->player.posx);
		sprite_y = (data->sprites[i][1] - data->player.posy);
		inv_det = 1.0 / (data->player.planex * data->player.diry - data->player.dirx * data->player.planey);
		trasfmor_x = inv_det * (data->player.diry * sprite_x - data->player.dirx * sprite_y);
		trasfmor_y = inv_det * (-data->player.planey * sprite_x + data->player.planex * sprite_y); //questa è effettivamente la profondità all'interno dello schermo, ovvero ciò che Z è in 3D
		sprite_screeen_x = (int)((screen_width / 2) * (1 + (trasfmor_x / trasfmor_y)));
		//calcola l'altezza dello sprite sullo schermo
		sprite_height = abs((int)(screen_height / (trasfmor_y))); //l'uso di 'transformY' al posto della distanza reale impedisce il fisheye
		//calcola il pixel più basso e più alto per riempire la striscia corrente
		draw_start_y = -sprite_height / 2 + screen_height / 2;
		if (draw_start_y < 0)
			draw_start_y = 0;
		draw_end_y = sprite_height / 2 + screen_height / 2;
		if (draw_end_y >= screen_height)
			draw_end_y = screen_height - 1;
		//calcola la larghezza della sprite
		sprite_width = abs((int)(screen_height / trasfmor_y));
		draw_start_x = -sprite_width / 2 + sprite_screeen_x;
		if (draw_start_x < 0)
			draw_start_x = 0;
		if (draw_end_x >= screen_width)
			draw_end_x = screen_width - 1;
		//scorre ogni striscia verticale della sprite sullo schermo
		stripe = draw_start_x;
		while (stripe < draw_end_x)
		{
			tex_x = (int)((256 * (stripe - (-sprite_width / 2 + sprite_screeen_x)) * data->sprite.width / sprite_width) / 256);
			if (trasfmor_y > 0 && stripe > 0 && stripe < screen_width && trasfmor_y < data->z_buffer[stripe])
			{
				y = draw_start_y;
				while (y < draw_end_y)
				{
					d = (y) * 256 - screen_height * 128 + sprite_height * 128;
					tex_y = ((d * data->sprite.height) / sprite_height) / 256;
					color_pixel = data->sprite.data[data->sprite.height * tex_y + tex_x];
					if ((color_pixel & 0x00FFFFFF) != 0)
						my_mlx_pixel_put(data, stripe, y, color_pixel);
					y++;
				}
			}
			stripe++;
		}
		i++;
	}
}

/*
///// STAMPARE A SCHERMO CIELO E TERRA SENZA TEXTURE /////
void	to_print_c_t(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < screen_height / 2)
	{
		x = 0;
		while (x < screen_width)
		{
			my_mlx_pixel_put(data, x, y, conv_color_pixel(169, 204, 227));
			x++;
		}
		y++; 
	}
	y = screen_height / 2;
	while (y < screen_height)
	{
		x = 0;
		while (x < screen_width)
		{
			my_mlx_pixel_put(data, x, y, conv_color_pixel(147, 81, 22));
			x++;
		}
		y++; 
	}
}
*/
int		render_next_frame(t_data *img)
{
	int		x;
	int		y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		h;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color_pixel;
	int		tex_x;
	int		tex_y;
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

	x = 0;
	h = screen_height;
	//to_print_c_t(img);
	to_print_txt_c_t(img);
	while (x < screen_width)
	{
		///// POSIZIONARE IL PLAYER /////
		camerax = ((2 * x) / (double)screen_width) - 1;
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
				side = 0;
			}
			else
			{
				side_disty += delta_disty;
				map_y += step_y;
				side = 1;
			}
			if (worldmap[map_x][map_y] > 0)
				hit = 1;
		}
		///// CALCOLA DISTANZA TRA PLAYER E IL MURO COLPITO /////
		if (side == 0)
			perp_wall_dist = ((map_x - img->player.posx + (1 - step_x) / 2) / ray_dirx);
		else
			perp_wall_dist = ((map_y - img->player.posy + (1 - step_y) / 2) / ray_diry);
		///// CALCOLA ALTEZZA DELLA LINEA DA DISEGNARE SULLO SCHERMO /////
		line_height = (int)(h / perp_wall_dist); //Calcola l'altezza della linea da disegnare sullo schermo. h é uguale all'altezza dello schermo
		draw_start = (-line_height / 2) + (h / 2); //draw_start  e draw_end calcola il pixel più basso e più alto per riempire la striscia corrente
		if (draw_start < 0)
			draw_start = 0;
		draw_end = (line_height / 2) + (h / 2);
		if (draw_end >= h)
			draw_end = h - 1;
		///// INSERIMENTO TEXTURE /////
		if (side == 0) //Calcola il valore di wallX
			wall_x = img->player.posy + perp_wall_dist * ray_diry;
		else
			wall_x = img->player.posx + perp_wall_dist * ray_dirx;
		wall_x -= floor((wall_x));
		tex_x = (int)(wall_x * img->nord_txt.width); //Coordinata x sulla texture
		if (side == 0 && ray_dirx > 0)
			tex_x = img->nord_txt.width - tex_x - 1;
		if (side == 1 && ray_diry < 0)
			tex_x = img->nord_txt.width - tex_x - 1;
		step = 1.0 * img->nord_txt.height / line_height; //Quanto aumentare la coordinata della texture per ogni pixel dello schermo
		tex_pos = (draw_start - h / 2 + line_height / 2) * step;
		y = draw_start;
		while (y < draw_end)
		{
			tex_y = (int)tex_pos & (img->nord_txt.height - 1);
			tex_pos += step;
			color_pixel = img->nord_txt.data[img->nord_txt.height * tex_y + tex_x];
			if (side == 1)
				color_pixel = (color_pixel >> 1) & 8355711; //Rende il colore più scuro per i lati y: R, G e B byte ciascuno diviso per due
			my_mlx_pixel_put(img, x, y, color_pixel);
			y++;
		}

/*
		///// COLORAZIONE DEI MURI /////
		if (worldmap[map_x][map_y] == 1)
			color_pixel = conv_color_pixel(255, 0, 0); //rosso
		else if (worldmap[map_x][map_y] == 2)
			color_pixel = conv_color_pixel(0, 255, 0); //verde
		else if (worldmap[map_x][map_y] == 3)
			color_pixel = conv_color_pixel(0, 0, 255); //blu
		else if (worldmap[map_x][map_y] == 4)
			color_pixel = conv_color_pixel(255, 255, 255); //bianco
		else
			color_pixel = conv_color_pixel(255, 255, 0); //giallo
		if (side == 1)
			color_pixel /= 2; //sfumatura
		ver_line(img, x, draw_start, draw_end, color_pixel);
*/
		img->z_buffer[x] = perp_wall_dist;
		x++;
	}
	to_sprite(img);
	move_and_close(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_do_sync(img->mlx);
	return (0);
}

///// CARICAMENTO TEXTURE /////
void		load_texture(t_data *data)
{
	data->nord_txt.img = mlx_xpm_file_to_image(data->mlx, "textures/txt/mur_neon.xpm", &data->nord_txt.width, &data->nord_txt.height);
	data->nord_txt.data = (unsigned int *)mlx_get_data_addr(data->nord_txt.img, &data->nord_txt.bits_per_pixel, &data->nord_txt.line_length, &data->nord_txt.endian);

	data->floor_txt.img = mlx_xpm_file_to_image(data->mlx, "textures/txt/sol_neon.xpm", &data->floor_txt.width, &data->floor_txt.height);
	data->floor_txt.data = (unsigned int *)mlx_get_data_addr(data->floor_txt.img, &data->floor_txt.bits_per_pixel, &data->floor_txt.line_length, &data->floor_txt.endian);

	data->sky_txt.img = mlx_xpm_file_to_image(data->mlx, "textures/txt/wall-1.xpm", &data->sky_txt.width, &data->sky_txt.height);
	data->sky_txt.data = (unsigned int *)mlx_get_data_addr(data->sky_txt.img, &data->sky_txt.bits_per_pixel, &data->sky_txt.line_length, &data->sky_txt.endian);
	/*
	data->sprite.img = mlx_xpm_file_to_image(data->mlx, "textures/txt/crystal_0", &data->sprite.width, &data->sprite.height);
	data->sprite.data = (unsigned int *)mlx_get_data_addr(data->sprite.img, &data->sprite.bits_per_pixel, &data->sprite.line_length, &data->sprite.endian);
	*/
	data->sprite.img = mlx_png_file_to_image(data->mlx, "textures/txt/pillar.png", &data->sprite.width, &data->sprite.height);
	data->sprite.data = (unsigned int *)mlx_get_data_addr(data->sprite.img, &data->sprite.bits_per_pixel, &data->sprite.line_length, &data->sprite.endian);
}

int		main()
{
    t_data  img;
	
    img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, screen_width, screen_height, "ANATRE IN MINI-RT");
    img.img = mlx_new_image(img.mlx, screen_width, screen_height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img.player = init_player(img.player);
	mlx_loop_hook(img.mlx, render_next_frame, &img);
	load_texture(&img);
	init_sprite(&img);
	mlx_hook(img.mlx_win, 17, 1L<<0, close_program_x, &img);
	mlx_hook(img.mlx_win, 2, 1L<<0, init_move_press, &img);
	mlx_hook(img.mlx_win, 3, 1L<<1, init_move_release, &img);
	mlx_hook(img.mlx_win, 06, 1L<<6, move_mouse, &img);
	mlx_loop(img.mlx);
}