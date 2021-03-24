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