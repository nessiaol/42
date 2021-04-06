#include "cub3d.h"

void	ft_draw_ver_line(int x, t_all *all, int color)
{
	while (all->ray.draw_start < all->ray.draw_end)
	{
		my_mlx_pixel_put(all, x, all->ray.draw_start, color);
		all->ray.draw_start++;
	}
}