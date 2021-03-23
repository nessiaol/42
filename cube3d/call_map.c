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

void	ft_draw_minimap(t_all *all)
{
	int x = 200;
    int y = 200;
	int i;

	i = 0;
	while(all->map.map_matrix[i])
	{
		printf("linea: %s\n", all->map.map_matrix[i]);
		ft_draw_line(all, x, y, i);
		y += PIXEL_SIZE;
		i++;
	}
}