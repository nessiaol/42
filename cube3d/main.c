#include "cub3d.h"

void		ft_init_window(t_all *all)
{
	all->mlx.mlx = mlx_init();
    all->mlx.win = mlx_new_window(all->mlx.mlx, all->map.res_x, all->map.res_y, "Cub3d");
    all->img.img = mlx_new_image(all->mlx.mlx, all->map.res_x, all->map.res_y);
    all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length,
								&all->img.endian);
}

void		ft_steps(t_all *all)   //calculate step and initial sideDist
{
	//all->ray.delta_dist_y = 1.55;
	//printf("delta dist x: %f  delta dist y: %f\n", all->ray.delta_dist_x, all->ray.delta_dist_y);
	if (all->ray.ray_dir_x < 0)    //entra qui
    {
		// printf("step x = -1\n");
    	all->ray.step_x = -1;
        all->ray.side_dist_x = (all->player.pos_x - all->ray.map_x) * all->ray.delta_dist_x;
		// printf("step x: %d  side distance x: %f\n", all->ray.step_x, all->ray.side_dist_x);
    }
    else   
    {
		// printf("step x = 1");
    	all->ray.step_x = 1;
    	all->ray.side_dist_x = (all->ray.map_x + 1.0 - all->player.pos_x) * all->ray.delta_dist_x;
		// printf("step x: %d  side distance x: %f", all->ray.step_x, all->ray.side_dist_x);
    }
    if (all->ray.ray_dir_y < 0)
    {
        // printf("step y = -1");
		all->ray.step_y = -1;
        all->ray.side_dist_y = (all->player.pos_y - all->ray.map_y) * all->ray.delta_dist_y;
		// printf("step x: %d  side distance x: %f", all->ray.step_x, all->ray.side_dist_x);
    }
    else  //entra qui
    {
		// printf("step y = 1\n");
        all->ray.step_y = 1;
        all->ray.side_dist_y = (all->ray.map_y + 1.0 - all->player.pos_y) * all->ray.delta_dist_y;
		// printf("step y: %d  side distance y: %f\n", all->ray.step_y, all->ray.side_dist_y);
    }

}

void		ft_perform_dda(t_all *all)  ///// DDA PER TROVARE QUANDO COLPISCI UN MURO /////
{
	all->ray.hit = 0;
    while (all->ray.hit == 0)
    {
		//jump to next map square, OR in x-direction, OR in y-direction
        if (all->ray.side_dist_x < all->ray.side_dist_y)
        {
        	all->ray.side_dist_x += all->ray.delta_dist_x;
        	all->ray.map_x += all->ray.step_x;
        	all->ray.side = 0;
        }
        else
        {
    		all->ray.side_dist_y += all->ray.delta_dist_y;
        	all->ray.map_y += all->ray.step_y;
        	all->ray.side = 1;
        }
        //Check if ray has hit a wall
        if (all->map.map_matrix[all->ray.map_x][all->ray.map_y] == '1')
			all->ray.hit = 1;
    } 
}

void		ft_calc_distance(t_all *all)  ///// CALCOLA DISTANZA TRA PLAYER E IL MURO COLPITO /////
{
    if (all->ray.side == 0)
		all->ray.perp_wall_dist = (all->ray.map_x - all->player.pos_x
		+ (1 - all->ray.step_x) / 2) / all->ray.ray_dir_x;
	else
	    all->ray.perp_wall_dist = (all->ray.map_y - all->player.pos_y
		+ (1 - all->ray.step_y) / 2) / all->ray.ray_dir_y;

	// Calcola l'altezza della linea da disegnare sullo schermo
    all->ray.line_height = (int)(all->map.res_y / all->ray.perp_wall_dist);
	//printf("line height: %d", all->ray.line_height);
    
	// calcola il pixel più basso e più alto per riempire la striscia corrente
    all->ray.draw_start = (-all->ray.line_height / 2) + (all->map.res_y / 2);
    if (all->ray.draw_start < 0)
		all->ray.draw_start = 0;
    all->ray.draw_end = (all->ray.line_height / 2) + (all->map.res_y / 2);
    if (all->ray.draw_end >= all->map.res_y)
		all->ray.draw_end = all->map.res_y - 1;
}

void		ft_put_player(int x, t_all *all)
{
	///// POSIZIONARE IL PLAYER /////

    	all->ray.camera_x = ((2 * x) / (double)all->map.res_x) - 1; //x-coordinate in camera space
    	all->ray.ray_dir_x = all->player.dir_x + (all->player.plane_x * all->ray.camera_x);
		all->ray.ray_dir_y = all->player.dir_y + (all->player.plane_y * all->ray.camera_x);
		// printf("ray dir x: %f  ray dir y: %f \n", all->ray.ray_dir_x, all->ray.ray_dir_y);
		all->ray.map_x = (int)all->player.pos_x;
		all->ray.map_y = (int)all->player.pos_y;
		// printf("map x: %d  map y: %d \n", all->ray.map_x, all->ray.map_y);
		if (all->ray.ray_dir_y == 0)
			all->ray.delta_dist_x = 0;
		else if (all->ray.ray_dir_x == 0)
			all->ray.delta_dist_x = 1;
		else
			all->ray.delta_dist_x = fabs(1 / all->ray.ray_dir_x);
		if (all->ray.ray_dir_x == 0)
			all->ray.delta_dist_y = 0;
		else if (all->ray.ray_dir_y == 0)
			all->ray.delta_dist_y = 1;
		else
			all->ray.delta_dist_y = fabs(1 / all->ray.ray_dir_y);
}



int			ft_render_map(t_all *all)
{
	int x = 0;
	// ft_key_register(all);
	ft_keypress(all);
	while (x < all->map.res_x)
    {
		ft_put_player(x, all);		//posiziona il player
		ft_steps(all);    			//calcula passi e distanza iniziale
		ft_perform_dda(all);		//calcola distanza dai muri
		ft_calc_distance(all);  	//calcola distanza secondo la direzione della camera
		
//------------------- colore dei muri
      
      	ft_draw_ver_line(x, all, 0x0000FFFF);  //draw the pixels of the stripe as a vertical line
		x++;
	}
	// mlx_destroy_image(all->mlx.mlx, all->img.img);
	// all->img.img = mlx_new_image(all->mlx.mlx, all->map.res_x, all->map.res_y);
    // all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length,
	// 							&all->img.endian);

	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
	return(0);
}	

int			main(int argc, char **argv)
{
	t_all				all;
    t_list          	*list;
	int 				fd;

	if (argc == 2)
	{
		if (!(fd = open(argv[1], O_RDONLY)))
			return (-1);
		list = ft_lstnew("");
		list = ft_check_options(fd, &all, list);
		
		ft_init_window(&all);
		ft_init_player(&all);
		ft_init_xy(&all);
		ft_init_rays(&all);

    	ft_check_map(fd, list);
		ft_list_to_matrix(&all, list);
		ft_find_player_pos(&all);
		// printf("player y: %f player x: %f\n", all.player.pos_y, all.player.pos_x);
		// printf("x: %d  y: %d\n", all.map.res_x, all.map.res_y);

		//mlx_destroy_image(all.mlx.mlx, all.img.img);
		//all.img.img = mlx_new_image(all.mlx.mlx, all.map.res_x, all.map.res_y);
		//ft_draw_minimap_first(&all);
		//mlx_put_image_to_window(all.mlx.mlx, all.mlx.win, all.img.img, 0, 0);
		//printf("prova1");
		mlx_loop_hook(all.mlx.mlx, ft_render_map, &all);
		// printf("player pos x: %f\n", all.player.pos_x);
		// printf("matrix line 4: %s\n", all.map.map_matrix[4]);
		// printf("matrix player pos: %c\n", all.map.map_matrix[(int)(all.player.pos_y)][(int)(all.player.pos_x)]);

		mlx_hook(all.mlx.win, KEYPRESS, KEYPRESSMASK, ft_key_hit, &all);
    	mlx_hook(all.mlx.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &all);
		//printf("player planey: %f\n", all.player.plane_y);
    	mlx_loop(all.mlx.mlx);
	}
	return(0);
}