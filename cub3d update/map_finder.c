/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_finder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stribuzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 18:47:44 by stribuzi          #+#    #+#             */
/*   Updated: 2021/03/30 15:58:30 by stribuzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	find_map_support_1(t_data *p, int map_height, int *fd, char *path)
{
	p->sprites = (int **)malloc(sizeof(int *) * p->num_sprite);
	if (!(p->sprites))
		throw_error(p, "Malloc failed!\n");
	if (map_height < 3)
		throw_error(p, "Error map too short! once again.. im sorry :(");
	fd[0] = open(path, O_RDONLY);
	p->map = (char **)malloc(sizeof(char *) * map_height);
	if (!(p->map))
		return ;
}

void	find_map_support_2(t_data *p, char *line, int *k)
{
	if (is_valid_map_line(line) == 0)
		throw_error(p, "Map not surrounded by walls!\n");
	p->map[k[0]] = ft_strdup(line);
	p = check_spawn_pos(p, line, k[0]);
	check_sprites(p, line, k[0]);
	k[0]++;
}

void	find_map(char *path, int map_height, t_data *p)
{
	int		fd;
	char	*line;
	int		k;

	find_map_support_1(p, map_height, &fd, path);
	k = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (only_number_and_spaces(line) == 1 && only_spaces(line) == 0)
			find_map_support_2(p, line, &k);
		free(line);
	}
	if (only_number_and_spaces(line) == 1 && only_spaces(line) == 0)
	{
		if (is_valid_map_line(line) == 0)
			throw_error(p, "Map not surrounded by walls!\n");
		p->map[k] = ft_strdup(line);
		k++;
	}
	check_first_and_last_line(p, map_height);
	free(line);
	close(fd);
}

void	set_to_zero(t_found *found)
{
	found->north_found = 0;
	found->south_found = 0;
	found->sprite_found = 0;
	found->east_found = 0;
	found->west_found = 0;
	found->floor_found = 0;
	found->ceiling_found = 0;
	found->spawn_pos = 0;
	found->res_found = 0;
}
