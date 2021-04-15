/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 09:30:06 by stribuzi          #+#    #+#             */
/*   Updated: 2021/04/14 20:31:58 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include <stdlib.h>
# include "get_next_line.h"
# include <math.h>
# include "mlx/mlx.h"
# include "define.h"

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
	char		initial_direction;
}				t_player;

typedef struct 	s_color 
{
	int			r;
    int			g;
	int			b;
}				t_color;

typedef	struct		s_found
{
	int				res_found;
	int				east_found;
	int				south_found;
	int				north_found;
	int				west_found;
	int				sprite_found;
	int				floor_found;
	int				ceiling_found;
	int				spawn_pos;
}					t_found;

typedef struct		s_get_sprite
{
	int			**support;
	int			support_num_sprite;
	double		sprite_x;
	double		sprite_y;
	double 		inv_det;
	double 		transform_x;
	double 		transform_y;
	int 		draw_start_y;
	int 		draw_start_x;
	int 		draw_end_y;
	int 		draw_end_x;
	int 		stripe;
	int			d;
	int 		sprite_height;
	int 		sprite_width;
	int			i;
	int 		sprite_screen_x;
	int			tex_x;
	int			tex_y;
	int			color_pixel;
	int			y;
	// int			sprite_order[data->num_sprite];
	// double		sprite_distance[data->num_sprite];
}					t_get_sprite;

typedef struct	s_data 
{
	void		*img;
	void		*window;
	char		*addr;
	int			side;
	int			bits_per_pixel;
    int			line_length;
    int			endian;
	int			num_sprite;
	int			**sprites;
	int			*sprite_order;
	int			screen_width;
	int			screen_height;
	int			do_screenshot;
	int			position_screenshot;
	int			sprite_count;
	double		*z_buffer;
	double		*sprite_distance;
	void		*mlx;
	void		*mlx_win;
	char		**map;
	int			floor_color;
	int			map_height;
	int			ceiling_color;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*sprite_texture;
	unsigned char *screenshot;
	int			initial_num_sprite;
	int			end_game;
	char		*buff;
	double		mov_speed;
	t_player	player;
	t_texture	nord_txt;
	t_texture	sud_txt;
	t_texture	est_txt;
	t_texture	ovest_txt;
	t_texture	floor_txt;
	t_texture	sky_txt;
	t_texture	sprite;
	t_texture	sprite_1;
	t_texture	end;
	t_texture	lifebar25;
	t_texture	lifebar50;
	t_texture	lifebar75;
	t_texture 	lifebar100;
	t_texture	heart;
	t_texture	sky_box;
	t_keycode	keycode;
	t_found 	found;
	t_get_sprite	get_sprite;
}				t_data;

void			check_error_texture(char *to_check, t_data *p);
void			check_if_file_exists(t_data *p, char *s1);
t_data			*find_resolution(t_data *p, char *line);
char			*find_texture(char *line, char *to_check, t_data *p);
int				is_spawn_pos(char c);
void			set_to_non_color(t_color *color);
int				find_color(t_data *p, char *line, char to_check);
void			check_if_file_exists(t_data *p, char *s1);
void			check_error_texture(char *to_check, t_data *p);
int				only_number_and_spaces(char *line);
int				only_spaces(char *line);
char			*allocate_map(char *to_return, char *line);
int				is_valid_map_line(char *line);
t_data			*check_spawn_pos(t_data *p, char *line, int k);
void			check_sprites(t_data *p, char *line, int k);
void			check_first_and_last_line(t_data *p, int map_height);
void			find_map(char *path, int map_height, t_data *p);
void			set_to_zero(t_found *found);
t_data			parse_info(char *path, t_data *p);
int				ft_strcmp(char *s1, char *s2);
int				is_number(char c);
int				is_space(char c);
int				ft_isprint(int c);
t_color			ft_int_to_rgb(int color);
int				is_printable(int c);
void 			throw_error(t_data *data, char *error);
void			mini_atoi(int *res, int *i, char *line);
int				ft_color_to_int(int red, int green, int blue);
void			ft_bzero(void *s, size_t n);
int				write_screenshot(t_data *p, unsigned char *pixels);
void			*ft_memset(void *str, int c, size_t n);
unsigned char	*create_bitmap_file_header(int height, int stride);
unsigned char	*create_bitmap_info_header(int height, int width);
int				is_wall(char c);
int				is_sprite(char c);

//UTILS 1
void			ft_sort(int *sprite_order, double *tab, int size);
void			ft_reverse(int *sprite_order, double *tab, int size);
float			ft_deg_to_rad(int deg);
int				ft_conv_color_pixel(int red, int green, int blue);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

//INITIALIZER
void			ft_init_movement(t_data *data);
void			init_player_2(t_player *player);
t_player		init_player(t_player player);

//SPRITES 1
void			to_sprite(t_data *data);
void			ft_draw_sprite_1(t_data *data);
void			ft_order_sprite(t_data *data, int *sprite_order, double *sprite_distance);
void			ft_calc_sprite(t_data *data, int *sprite_order, double *sprite_distance);

//SPRITES 2
void			ft_count_sprite_game(t_data *data);
void			ft_count_sprite_2(t_data *data, int x);

#endif
