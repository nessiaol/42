/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nuovo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 13:31:04 by bde-luca          #+#    #+#             */
/*   Updated: 2021/03/24 19:09:41 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_render_map(t_all *all)
{
	ft_draw_minimap_first(all);
	mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->img.img, 0, 0);
	ft_key_register(all);
	return(0);
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
		//ft_init_keys(&all);
		ft_init_xy(&all);

    	ft_check_map(fd, list);
		ft_list_to_matrix(&all, list);
		
		mlx_hook(all.mlx.win, KEYPRESS, KEYPRESSMASK, ft_key_hit, &all);
    	mlx_hook(all.mlx.win, KEYRELEASE, KEYRELEASEMASK, ft_key_release, &all);
		mlx_loop_hook(all.mlx.mlx, ft_render_map, &all);
    	mlx_loop(all.mlx.mlx);
	}
}