#include "parser.h"

void	ft_sort(int *sprite_order, double *tab, int size)
{
	int		i;
	int		a;
	double	temp;
	int		temp_2;

	temp_2 = 0;
	temp = 0;
	i = 0;
	a = 0;
	while (i < size)
	{
		a = i + 1;
		while (a < size)
		{
			if (tab[i] > tab[a])
			{
				temp = tab[i];
				tab[i] = tab[a];
				tab[a] = temp;
				temp_2 = sprite_order[i];
				sprite_order[i] = sprite_order[a];
				sprite_order[a] = temp_2;
			}
			a++;
		}
		i++;
	}
}

void	ft_reverse(int *sprite_order, double *tab, int size)
{
	int		i;
	double	temp;
	int		temp_2;

	temp_2 = 0;
	i = 0;
	while (i < size / 2)
	{
		temp = tab[size - 1 - i];
		tab[size - 1 - i] = tab[i];
		tab[i] = temp;
		temp_2 = sprite_order[size - 1 - i];
		sprite_order[size - 1 - i] = sprite_order[i];
		sprite_order[i] = temp_2;
		i++;
	}
}

float	ft_deg_to_rad(int deg)
{
	float	rad;

	rad = deg * M_PI / 180;
	return (rad);
}

//inutilizzata?
int	ft_conv_color_pixel(int red, int green, int blue)
{
	int		rgb;

	rgb = red;
	rgb = (rgb << 8) + green;
	rgb = (rgb << 8) + blue;
	return (rgb);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
