#include "cub3d.h"

void            my_mlx_pixel_put(t_all *all, int x, int y, int color)
{
    char    *dst;
    dst = all->img.addr + (y * all->img.line_length + x * (all->img.bits_per_pixel) / 8);
    *(unsigned int*)dst = color;
}

void        draw_pixel_size(t_all *all, int x, int y, int color)
{
    int l;
    int h;

    h = y;
    l = x;
    while (h < (y + PIXEL_SIZE))
    {
        l = x;
        while (l < (x + PIXEL_SIZE))
        {
            my_mlx_pixel_put(all, l, h, color);                   
            l++;
        }
        h++;
    }
}

void		ft_check_start_dir(t_all *all, char c)
{
	ft_init_direction(all);
	if (c == 'N')
		all->direction.north = 1;
	if (c == 'S')
		all->direction.south = 1;
	if (c == 'W')
		all->direction.west = 1;
	if (c == 'E')
		all->direction.east = 1;
}

void		ft_draw_png(t_all *all, int x, int y, int color)
{
	int l;
    int h;

    h = y;
    l = x;

	color = 0x00FFFF00;

    while (h < (y + PNG_SIZE))
    {
        l = x;
        while (l < (x + PNG_SIZE))
        {
            my_mlx_pixel_put(all, l, h, color);   
			//mlx_pixel_put(all->mlx.mlx, all->mlx.win, l, h, color);
            l++;
        }
        h++;
    }
	//mlx_pixel_put(all->mlx.mlx, all->mlx.win, x, y, color);
}

void        ft_draw_line_first(t_all *all, int x, int y, int i)
{
    int j;

    j = 0;
    while(all->map.map_matrix[i][j] != '\0')
    {
        if (all->map.map_matrix[i][j] == '1')
        {
			draw_pixel_size (all, x, y, 0x0000FFFF);
            x += PIXEL_SIZE;
        }
		else if (all->map.map_matrix[i][j] == '2')
		{
            draw_pixel_size (all, x, y, 0x00FF0000);
            x += PIXEL_SIZE;
        }
		else if( all->map.map_matrix[i][j] == 'N' || all->map.map_matrix[i][j] == 'S' ||
				all->map.map_matrix[i][j] == 'W' || all->map.map_matrix[i][j] == 'E')
		{
			all->png.py = y;
			all->png.px = x;
			ft_check_start_dir(all, all->map.map_matrix[i][j]);
			my_mlx_pixel_put(all, all->png.px, all->png.py, 0x00FFFF00);
			ft_draw_png(all, x, y, 0x00FFFF00);
			x += PIXEL_SIZE;
		}
        else if (all->map.map_matrix[i][j] == '0')
        {
            x += PIXEL_SIZE;   
        }
        j++;
    }
}

void        ft_draw_line(t_all *all, int x, int y, int i)
{
    int j;

    j = 0;
    while(all->map.map_matrix[i][j] != '\0')
    {
        if (all->map.map_matrix[i][j] == '1')
        {
			draw_pixel_size (all, x, y, 0x0000FFFF);
            x += PIXEL_SIZE;
        }
		else if (all->map.map_matrix[i][j] == '2')
		{
            draw_pixel_size (all, x, y, 0x00FF0000);
            x += PIXEL_SIZE;
        }
		else if( all->map.map_matrix[i][j] == 'N' || all->map.map_matrix[i][j] == 'S' ||
				all->map.map_matrix[i][j] == 'W' || all->map.map_matrix[i][j] == 'E')
		{
			ft_check_start_dir(all, all->map.map_matrix[i][j]);
			ft_draw_png(all, all->png.px, all->png.py, 0x00FFFF00);
			//printf("x: %d, y: %d\n", all->png.px, all->png.py);
			x += PIXEL_SIZE;
		}
        else if (all->map.map_matrix[i][j] == '0')
        {
            x += PIXEL_SIZE;   
        }
        j++;
    }
}
