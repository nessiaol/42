#include "parser.h"

void	ft_init_movement(t_data *data)
{
	data->mov_speed = 0.3;
}

void	init_player_2(t_player *player)
{
	if (player->initial_direction == 'E')
	{
		player->dirx = 0;
		player->diry = 1;
		player->planex = 0.66;
		player->planey = 0;
	}
	else if (player->initial_direction == 'W')
	{
		player->dirx = 0;
		player->diry = -1;
		player->planex = -0.66;
		player->planey = 0;
	}
}

t_player	init_player(t_player player)
{
	if (player.initial_direction == 'N')
	{
		player.dirx = -1;
		player.diry = 0;
		player.planex = 0;
		player.planey = 0.66;
	}
	else if (player.initial_direction == 'S')
	{
		player.dirx = 1;
		player.diry = 0;
		player.planex = 0;
		player.planey = -0.66;
	}
	init_player_2(&player);
	return (player);
}
