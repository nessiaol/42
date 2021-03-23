#include "cub3d.h"

void	ft_init_direction(t_all *all)
{
	all->direction.north = 0;
	all->direction.south = 0;
	all->direction.west = 0;
	all->direction.east = 0;
}

void	ft_init_keys(t_all *all)
{
	all->keys.w = 0;
	all->keys.a = 0;
	all->keys.s = 0;
	all->keys.d = 0;
	all->keys.esc = 0;
}