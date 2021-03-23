#include "cub3d.h"

void	ft_draw_visual_line(t_all *all, int color)
{
	int l;
    int h;
	int i = 0;

    h = all->png.py;
    l = all->png.px;

	if (all->direction.north == 1)
    {
		while (h > (all->png.py - 50))
    	{
            my_mlx_pixel_put(all, l, h, color);                   
           	h--;
    	}
		h = all->png.py;
    	l = all->png.px;
		while (i < 50)
		{
			my_mlx_pixel_put(all, l, h, color);
			h--;
			l++;
			i++;
		}
		i = 0;
		h = all->png.py;
    	l = all->png.px;
		while (i < 50)
		{
			my_mlx_pixel_put(all, l, h, color);
			h--;
			l--;
			i++;
		}
	}
	// else if (all->direction.south == 1)
    // {
	// 	while (h < (y + 50))
    // 	{
    //         my_mlx_pixel_put(all, l, h, color);                   
    //        	h++;
    // 	}
	// }
	// else if (all->direction.west == 1)
    // {
	// 	while (l > (x - 50))
    // 	{
    //         my_mlx_pixel_put(all, l, h, color);                   
    //        	l--;
    // 	}
	// }
	// else if (all->direction.east == 1)
    // {
	// 	while (l < (x + 50))
    // 	{
    //         my_mlx_pixel_put(all, l, h, color);                   
    //        	l++;
    // 	}
	// }
	return;
}