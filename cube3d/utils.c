#include "cub3d.h"

float deg_to_rad(int deg) //Funzione conversione da gradi a radianti
{
	float rad;

	rad = deg * M_PI / 180;
	return (rad);
}

int		conv_color_pixel(int red, int green, int blue)
{
	int rgb;

	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}

