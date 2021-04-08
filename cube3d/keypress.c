#include "cub3d.h"

int		ft_keypress(t_all *all)
{
	if (all->keyboard.keyboard[13])	//AVANTI
	{
		ft_move_forward(all);
	}
	if (all->keyboard.keyboard[1])	//INDIETRO
	{
		ft_move_backward(all);
	}
	if (all->keyboard.keyboard[0]) //SINISTRA
	{
		ft_move_left(all);
	}
	if (all->keyboard.keyboard[2]) //DESTRA
	{
		ft_move_right(all);
	}
	// if (all->keyboard.keyboard[46]) //	MINIMAPPA
	// {
	// 	mlx_destroy_image(all->mlx.mlx, all->img.img);
	// 	all->img.img = mlx_new_image(all->mlx.mlx, all->map.res_x, all->map.res_y);
    // 	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length,
	// 							&all->img.endian);
	// 	ft_draw_minimap(all);
	// 	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
	// }
	if (all->keyboard.keyboard[124])
	{
		all->camera.old_dir_x = all->player.dir_x;
		all->player.dir_x = all->player.dir_x * cos(-(all->camera.rot_speed)) - all->player.dir_y * sin(-all->camera.rot_speed);
		all->player.dir_y = all->camera.old_dir_x * sin(-(all->camera.rot_speed)) + all->player.dir_y * cos(-all->camera.rot_speed);
		all->camera.old_plane_x = all->player.plane_x;
		all->player.plane_x = all->player.plane_x * cos(-(all->camera.rot_speed)) - all->player.plane_y * sin(-all->camera.rot_speed);
		all->player.plane_y = all->camera.old_plane_x * sin(-(all->camera.rot_speed)) + all->player.plane_y * cos(-all->camera.rot_speed);
	}
	if (all->keyboard.keyboard[123])
	{
		all->camera.old_dir_x = all->player.dir_x;
		all->player.dir_x = all->player.dir_x * cos(all->camera.rot_speed) - all->player.dir_y * sin(all->camera.rot_speed);
		all->player.dir_y = all->camera.old_dir_x * sin(all->camera.rot_speed) + all->player.dir_y * cos(all->camera.rot_speed);
		all->camera.old_plane_x = all->player.plane_x;
		all->player.plane_x = all->player.plane_x * cos(all->camera.rot_speed) - all->player.plane_y * sin(all->camera.rot_speed);
		all->player.plane_y = all->camera.old_plane_x * sin(all->camera.rot_speed) + all->player.plane_y * cos(all->camera.rot_speed);
	}
	if (all->keyboard.keyboard[53])
	{
		mlx_destroy_image(all->mlx.mlx, all->img.img);
		mlx_destroy_window(all->mlx.mlx, all->mlx.win);
		exit (0);
	}
	
	mlx_destroy_image(all->mlx.mlx, all->img.img);
	all->img.img = mlx_new_image(all->mlx.mlx, all->map.res_x, all->map.res_y);
    all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length,
								&all->img.endian);
	//ft_draw_minimap(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
	return(0);
}

void	ft_move_forward(t_all *all)
{
	if (all->map.map_matrix[(int)(all->player.pos_x + all->player.dir_x
		* all->ray.movespeed)][(int)(all->player.pos_y)] != '1')
		all->player.pos_x += all->player.dir_x * all->ray.movespeed;
    if (all->map.map_matrix[(int)(all->player.pos_x)][(int)(all->player.pos_y
		+ all->player.dir_y * all->ray.movespeed)] != '1')
		all->player.pos_y += all->player.dir_y * all->ray.movespeed;
}

void	ft_move_backward(t_all *all)
{
	if (all->map.map_matrix[(int)(all->player.pos_x - all->player.dir_x
		* all->ray.movespeed)][(int)(all->player.pos_y)] != '1')
		all->player.pos_x -= all->player.dir_x * all->ray.movespeed;
    if (all->map.map_matrix[(int)(all->player.pos_x)][(int)(all->player.pos_y
		- all->player.dir_y * all->ray.movespeed)] != '1')
		all->player.pos_y -= all->player.dir_y * all->ray.movespeed;
}

void	ft_move_left(t_all *all)
{
	if (all->map.map_matrix[(int)(all->player.pos_x + all->player.dir_x
		* all->ray.movespeed)][(int)(all->player.pos_y)] != '1')
		all->player.pos_y += all->player.dir_x * all->ray.movespeed;
    if (all->map.map_matrix[(int)(all->player.pos_x)][(int)(all->player.pos_y
		+ all->player.dir_y * all->ray.movespeed)] != '1')
		all->player.pos_x -= all->player.dir_y * all->ray.movespeed;
}

void	ft_move_right(t_all *all)
{
	if (all->map.map_matrix[(int)(all->player.pos_x - all->player.dir_x
		* all->ray.movespeed)][(int)(all->player.pos_y)] != '1')
		all->player.pos_y -= all->player.dir_x * all->ray.movespeed;
    if (all->map.map_matrix[(int)(all->player.pos_x)][(int)(all->player.pos_y
		+ all->player.dir_y * all->ray.movespeed)] != '1')
		all->player.pos_x -= all->player.dir_y * all->ray.movespeed;
}