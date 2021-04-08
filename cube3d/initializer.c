#include "cub3d.h"

void	ft_init_direction(t_all *all)
{
	all->direction.north = 0;
	all->direction.south = 0;
	all->direction.west = 0;
	all->direction.east = 0;
}

void	ft_init_xy(t_all *all)
{
	all->map.start_x = 0;
	all->map.start_y = 0;
}

void	ft_init_player(t_all *all)
{
	all->player.dir_x = -1;
	all->player.dir_y = 0;
	all->player.plane_x = 0;
	all->player.plane_y = 0.66;
}

void	ft_init_rays(t_all *all)
{
	all->ray.camera_x = 0;
	all->ray.camera_y = 0;
	all->ray.time = 0;
	all->ray.oldtime = 0;
	all->ray.ray_dir_x = 0;
	all->ray.ray_dir_y = 0;
	all->ray.movespeed = 0.08;
	all->camera.rot_speed = 0.05;
	all->texture.height = 64;
	all->texture.width = 64;
}