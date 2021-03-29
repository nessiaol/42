#include "cub3d.h"

void		ft_init_window(t_all *all)
{
	all->mlx.mlx = mlx_init();
    all->mlx.win = mlx_new_window(all->mlx.mlx, all->map.res_x, all->map.res_y, "Cub3d");
    all->img.img = mlx_new_image(all->mlx.mlx, all->map.res_x, all->map.res_y);
    all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length,
								&all->img.endian);
}


int			ft_render_map(t_all *all)
{
	int x = 0;

	while (x < all->map.res_x)
    {
		//calculate ray position and direction
    	double cameraX = 2 * x / double(w) - 1; //x-coordinate in camera space
    	double rayDirX = dirX + planeX * cameraX;
    	double rayDirY = dirY + planeY * cameraX;
		x++;
	}
	ft_key_register(all);
	return(0);
}	

int			main(int argc, char **argv)
{
	t_all				all;
    t_list          	*list;
	int 				fd;

	double posX = 22, posY = 12;  //x and y start position
	double dirX = -1, dirY = 0; //initial direction vector
	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
	double time = 0; //time of current frame
  	double oldTime = 0; //time of previous frame

		if (argc == 2)
	{
		if (!(fd = open(argv[1], O_RDONLY)))
			return (-1);
		list = ft_lstnew("");
		list = ft_check_options(fd, &all, list);
		
		ft_init_window(&all);
		ft_init_xy(&all);

    	ft_check_map(fd, list);
		ft_list_to_matrix(&all, list);

		mlx_destroy_image(all.mlx.mlx, all.img.img);
		all.img.img = mlx_new_image(all.mlx.mlx, all.map.res_x, all.map.res_y);
		ft_draw_minimap_first(&all);
		mlx_put_image_to_window(all.mlx.mlx, all.mlx.win, all.img.img, 0, 0);

		
		mlx_hook(all.mlx.win, KEYPRESS, KEYPRESSMASK, ft_key_hit, &all);
    	mlx_hook(all.mlx.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &all);
		mlx_loop_hook(all.mlx.mlx, ft_render_map, &all);
    	mlx_loop(all.mlx.mlx);
	}
	return(0);
}