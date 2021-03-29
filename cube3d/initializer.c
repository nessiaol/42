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

void	ft_init_rays(t_all *all)
{
	all->ray.camera_x = 0;
	all->ray.camera_y = 0;
	all->ray.pos_x = 22;
	all->ray.pos_y = 12;
	all->ray.time = 0;
	all->ray.oldtime = 0;
	all->ray.plane_x = 0;
	all->ray.plane_y = 0.66;
	all->ray.ray_dir_x = 0;
	all->ray.ray_dir_y = 0;
	all->ray.dir_x = -1;
	all->ray.dir_y = 0;
}