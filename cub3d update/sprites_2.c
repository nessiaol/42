#include "parser.h"


void	ft_count_sprite_game(t_data *data)
{
	int	x;

	x = 0;
	if (is_sprite(data->map[(int)(data->player.posx)]
			[(int)(data->player.posy)]) == 1)
	{
		data->map[(int)(data->player.posx)][(int)(data->player.posy)] = '0';
		data->get_sprite.support = malloc(sizeof(int *) * data->num_sprite);
		if (!data->get_sprite.support)
			return ;
		while (x < data->num_sprite - 1)
		{
			data->get_sprite.support[x] = malloc(sizeof(int) * 2);
			data->get_sprite.support[x][0] = data->sprites[x][0];
			data->get_sprite.support[x][1] = data->sprites[x][1];
			x++;
		}
		free(data->sprites);
		ft_count_sprite_2(data, x);
	}
	if (data->sprite_count == data->initial_num_sprite)
		data->end_game = 1;
}

void	ft_count_sprite_2(t_data *data, int x)
{
	data->sprites = malloc(sizeof(int *) * data->num_sprite);
	if (!data->sprites)
		return ;
	x = 0;
	while (x < data->num_sprite - 1)
	{
		data->sprites[x] = malloc(sizeof(int) * 2);
		data->sprites[x][0] = data->get_sprite.support[x][0];
		data->sprites[x][1] = data->get_sprite.support[x][1];
		x++;
	}
	free(data->get_sprite.support);
	data->sprite_count++;
	data->num_sprite--;
}
