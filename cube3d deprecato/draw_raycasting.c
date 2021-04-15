#include "cub3d.h"

void	ft_draw_ver_line(int x, t_all *all, int color)
{
	while (all->ray.draw_start < all->ray.draw_end)
	{
		my_mlx_pixel_put(all, x, all->ray.draw_start, color);
		all->ray.draw_start++;
	}
}

void	ft_put_texture(int x, t_all *all)
{
	int i;

	ft_check_text_side(all);
	all->texture.step = 1.0 * all->north.height / all->ray.line_height;
	all->texture.position = (all->ray.draw_start - all->map.res_y / 2 + all->ray.line_height / 2) * all->texture.step;
	i = all->ray.draw_start;
	while (i < all->ray.draw_end)
	{
		all->texture.texture_y = (int)all->texture.position & (all->north.height - 1);
		all->texture.position += all->texture.step;
		if (all->ray.side == 0)
			all->texture.color_pixel = all->north.data[all->north.height * all->texture.texture_y + all->texture.texture_x];
		if (all->ray.side == 1)
			all->texture.color_pixel = all->south.data[all->south.height * all->texture.texture_y + all->texture.texture_x];
		if (all->ray.side == 2)
			all->texture.color_pixel = all->east.data[all->east.height * all->texture.texture_y + all->texture.texture_x];
		if (all->ray.side == 3)
			all->texture.color_pixel = all->west.data[all->west.height * all->texture.texture_y + all->texture.texture_x];
		if (all->ray.side == 1 || all->ray.side == 3)
			all->texture.color_pixel = (all->texture.color_pixel >> 1) & 8355711;
		my_mlx_pixel_put(all, x, i, all->texture.color_pixel);
		i++;
	}
}

void	ft_check_text_side(t_all *all)
{
	if (all->ray.side == 0 || all->ray.side == 2)
		all->texture.wall_x = all->player.pos_y + all->ray.perp_wall_dist * all->ray.ray_dir_y;
	else
		all->texture.wall_x = all->player.pos_x + all->ray.perp_wall_dist * all->ray.ray_dir_x;
	all->texture.wall_x -= floor(all->texture.wall_x);
	all->texture.texture_x = (int)((all->texture.wall_x) * (all->north.width));
	if (all->ray.side == 0 && all->ray.ray_dir_x > 0)
		all->texture.texture_x = all->north.width - all->texture.texture_x - 1;
	if (all->ray.side == 1 && all->ray.ray_dir_y < 0)
		all->texture.texture_x = all->south.width - all->texture.texture_x - 1;
	if (all->ray.side == 2 && all->ray.ray_dir_y < 0)
		all->texture.texture_x = all->east.width - all->texture.texture_x - 1;
	if (all->ray.side == 3 && all->ray.ray_dir_y < 0)
		all->texture.texture_x = all->west.width - all->texture.texture_x - 1;
}

void	ft_load_texture(t_all *all)
{
	all->north.img = mlx_png_file_to_image(all->mlx.mlx, all->map.north_texture, &all->north.width, &all->north.height);
	all->north.data = (unsigned int *)mlx_get_data_addr(all->north.img, &all->north.bits_per_pixel, &all->north.line_lenght, &all->north.endian);
	all->south.img = mlx_png_file_to_image(all->mlx.mlx, all->map.south_texture, &all->south.width, &all->south.height);
	all->south.data = (unsigned int *)mlx_get_data_addr(all->south.img, &all->south.bits_per_pixel, &all->south.line_lenght, &all->south.endian);
	all->west.img = mlx_png_file_to_image(all->mlx.mlx, all->map.west_texture, &all->west.width, &all->west.height);
	all->west.data = (unsigned int *)mlx_get_data_addr(all->west.img, &all->west.bits_per_pixel, &all->west.line_lenght, &all->west.endian);
	all->east.img = mlx_png_file_to_image(all->mlx.mlx, all->map.east_texture, &all->east.width, &all->east.height);
	all->east.data = (unsigned int *)mlx_get_data_addr(all->east.img, &all->east.bits_per_pixel, &all->east.line_lenght, &all->east.endian);
}
