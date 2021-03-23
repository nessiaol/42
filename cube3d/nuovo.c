/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nuovo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:31:04 by bde-luca          #+#    #+#             */
/*   Updated: 2021/03/23 16:28:44 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_draw(t_all *all, t_list *list)
{
	// int i = 0;

	ft_list_to_matrix(all, list);
	ft_draw_minimap(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
	mlx_hook(all->mlx.win, 2, 1L<<0, key_hook, all);
}


int            key_hook(int keycode, t_all *all)
{
    if (keycode == 53)
    {
        mlx_destroy_window(all->mlx.mlx, all->mlx.win);
        exit (0);
    }
	if (keycode == 13)
	{
		all->png.py -= 10;
		printf("prova w\n");
		// ft_check_map(fd, all, list);
		// mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
	}
	//ft_check_map(fd, all, list);
	//mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
	return (0);
}

void		ft_init_window(t_all *all)
{
	all->mlx.mlx = mlx_init();
    all->mlx.win = mlx_new_window(all->mlx.mlx, all->map.res_x, all->map.res_y, "Cub3d");
    all->img.img = mlx_new_image(all->mlx.mlx, all->map.res_x, all->map.res_y);
    all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length,
								&all->img.endian);
}

int             main(int argc, char **argv)
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
		ft_init_keys(&all);
		//ft_draw(&all);
	
		
		// // //LOOP CON REFRESH MAPPA
		// // //ft_loop_map(all.mlx.mlx, render_next_frame, &all);
    	ft_check_map(fd, list);
		ft_draw(&all, list);
		// ft_list_to_matrix(&all, list);
		// ft_draw_minimap(&all);
		// mlx_put_image_to_window(all.mlx.mlx, all.mlx.win, all.img.img, 0, 0);
		// mlx_hook(all.mlx.win, 2, 1L<<0, key_hook, &all);
    	mlx_loop(all.mlx.mlx);
	}
}