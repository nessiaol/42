#include "cub3d.h"

int ft_key_hit(int keycode, t_all *all)
{
    all->keyboard.keyboard[keycode] = 1;
    return (0);
}

int ft_key_release(int keycode, t_all *all)
{
    all->keyboard.keyboard[keycode] = 0;
    return (0);
}

int ft_key_register(t_all *all)
{
    if (all->keyboard.keyboard[13])
        ft_forward(all);
    if (all->keyboard.keyboard[1])
        ft_backward(all);
	if (all->keyboard.keyboard[0])
        ft_left(all);
	if (all->keyboard.keyboard[2])
        ft_right(all);
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
	return (0);
}

void	ft_forward(t_all *all)
{
	all->png.py -= 10;
}

void	ft_backward(t_all *all)
{
	all->png.py += 10;
}

void	ft_left(t_all *all)
{
	all->png.px -= 10;
}

void	ft_right(t_all *all)
{
	all->png.px += 10;
}