#include "cub3d.h"

void		ft_list_to_matrix(t_all *all, t_list *list)
{
	int i;
	
	i = 0;
	all->map.map_matrix = calloc((ft_lstsize(list) + 1), sizeof(char *));
	while (!(list->next == NULL))
	{
		all->map.map_matrix[i] = list->content;
		list = list->next;
		i++;
	}
}

void	ft_find_player_pos(t_all *all)
{
	int	y;
    int	x;

	y = 0;
    
	// printf("entra in find player \n");
    while (all->map.map_matrix[y])
	{
		//printf("linea matrix: %s\n", all->map.map_matrix[y]);
		x = 0;
		while(all->map.map_matrix[y][x] != '\0')
    	{
			
        	if (all->map.map_matrix[y][x] == 'N' || all->map.map_matrix[y][x] == 'S' ||
				all->map.map_matrix[y][x] == 'W' || all->map.map_matrix[y][x] == 'E')
			{
				// printf("trovato!\n");
				all->player.pos_y = x + 0.2;
				all->player.pos_x = y + 0.2;
				//printf("pos x: %f pos y: %f", all->player.pos_x, all->player.pos_y);
        	}
        	x++;
    	}
		y++;
	}
}


void	ft_draw_minimap_first(t_all *all)
{
	int x = all->map.start_x;
    int y = all->map.start_y;
	int i;

	i = 0;
	while (all->map.map_matrix[i])
	{
		//printf("linea: %s\n", all->map.map_matrix[i]);
		ft_draw_line_first(all, x, y, i);
		y += PIXEL_SIZE;
		i++;
	}
}

void	ft_draw_minimap(t_all *all)
{
	int x = all->map.start_x;
    int y = all->map.start_y;
	int i;

	i = 0;
	while(all->map.map_matrix[i])
	{
		//printf("linea: %s\n", all->map.map_matrix[i]);
		ft_draw_line(all, x, y, i);
		y += PIXEL_SIZE;
		i++;
	}
}