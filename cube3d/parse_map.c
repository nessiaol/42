#include "cub3d.h"

void		ft_parse_textures(t_all *all, t_list *list)
{
	int i;

	i = 0;
	if (list->content[0] == 'N' && list->content[1] == 'O')
        all->map.north_texture = ft_substr(list->content, 3, (ft_strlen(list->content)-3));
	else if (list->content[0] == 'S' && list->content[1] == 'O')
        all->map.south_texture = ft_substr(list->content, 3, (ft_strlen(list->content)-3));
	else if (list->content[0] == 'W' && list->content[1] == 'E')
         all->map.west_texture = ft_substr(list->content, 3, (ft_strlen(list->content)-3));
	else if (list->content[0] == 'E' && list->content[1] == 'A')
    	all->map.east_texture = ft_substr(list->content, 3, (ft_strlen(list->content)-3));
	else if (list->content[0] == 'S' && list->content[1] == ' ')
        all->map.sprite_texture = ft_substr(list->content, 2, (ft_strlen(list->content)-2));
}

void		ft_floor_color(t_all *all, t_list *list)
{
	int i;

	i = 0;
	if (list->content[i] == 'F' && list->content[i + 1] == ' ')
    {
        while (!(ft_isdigit(list->content[i])))
			i++;
		all->map.f_red = ft_atoi(&list->content[i]);
		while ((ft_isdigit(list->content[i])))
			i++;
		i++;
		all->map.f_green = ft_atoi(&list->content[i]);
		while ((ft_isdigit(list->content[i])))
			i++;
		i++;
		all->map.f_blue = ft_atoi(&list->content[i]);
		all->map.color_floor = ft_create_trgb(all->map.f_red, all->map.f_green, all->map.f_blue);
    }
}

void		ft_ceiling_color(t_all *all, t_list *list)
{
	int i;
	int color;
	char *rgbcolor;

	i = 0;
	if (list->content[i] == 'C' && list->content[i + 1] == ' ')
    {
        while (!(ft_isdigit(list->content[i])))
			i++;
		all->map.c_red = ft_atoi(&list->content[i]);
		while ((ft_isdigit(list->content[i])))
			i++;
		i++;
		all->map.c_green = ft_atoi(&list->content[i]);
		while ((ft_isdigit(list->content[i])))
			i++;
		i++;
		all->map.c_blue = ft_atoi(&list->content[i]);
		// printf("colore soffitto rosso: %d verde: %d blu: %d\n", all->map.c_red, all->map.c_green, all->map.c_blue);
		color = ft_create_trgb(all->map.c_red, all->map.c_green, all->map.c_blue);
		// printf("colore soffitto rgb: %d\n", color);
		rgbcolor = ft_itoa(color);
		all->map.color_ceiling = ft_strjoin("0x", rgbcolor);
		// printf("colore soffitto: %s\n", all->map.color_ceiling);
	}
}

void		ft_line_parsing_one(t_all *all, t_list *list)
{
	int i;

	i = 0;
	while(list->content[i] != '\0')
    {
		if (list->content[i] == 'R' && list->content[i + 1] == ' ')
        {
            while (!(ft_isdigit(list->content[i])))
				i++;
			all->map.res_x = ft_atoi(&list->content[i]);
			while ((ft_isdigit(list->content[i])))
				i++;
			all->map.res_y = ft_atoi(&list->content[i]);
		}
		ft_parse_textures(all, list);
		ft_floor_color(all, list);
		ft_ceiling_color(all, list);
		i++;
	}
}

int		ft_create_trgb(int red, int green, int blue)
{
	int rgb;

	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}



// int		create_trgb(int t, int r, int g, int b)
// {
// 	return(t << 24 | r << 16 | g << 8 | b);
// }