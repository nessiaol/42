#include "cub3d.h"

void	ft_rot_camera_right(t_all *all)
{
	all->camera.old_dir_x = all->player.dir_x;
	all->player.dir_x = all->player.dir_x * cos(-(all->camera.rot_speed)) - all->player.dir_y * sin(-all->camera.rot_speed);
	all->player.dir_y = all->camera.old_dir_x * sin(-(all->camera.rot_speed)) + all->player.dir_y * cos(-all->camera.rot_speed);
	all->camera.old_plane_x = all->player.plane_x;
	all->player.plane_x = all->player.plane_x * cos(-(all->camera.rot_speed)) - all->player.plane_y * sin(-all->camera.rot_speed);
	all->player.plane_y = all->camera.old_plane_x * sin(-(all->camera.rot_speed)) + all->player.plane_y * cos(-all->camera.rot_speed);	
}

void	ft_rot_camera_left(t_all *all)
{
	all->camera.old_dir_x = all->player.dir_x;
	all->player.dir_x = all->player.dir_x * cos(all->camera.rot_speed) - all->player.dir_y * sin(all->camera.rot_speed);
	all->player.dir_y = all->camera.old_dir_x * sin(all->camera.rot_speed) + all->player.dir_y * cos(all->camera.rot_speed);
	all->camera.old_plane_x = all->player.plane_x;
	all->player.plane_x = all->player.plane_x * cos(all->camera.rot_speed) - all->player.plane_y * sin(all->camera.rot_speed);
	all->player.plane_y = all->camera.old_plane_x * sin(all->camera.rot_speed) + all->player.plane_y * cos(all->camera.rot_speed);
}