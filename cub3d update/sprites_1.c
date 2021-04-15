#include "parser.h"

void	to_sprite(t_data *data)
{
	int			sprite_order[SP_NUM];
	double		sprite_distance[SP_NUM];
	
	ft_order_sprite(data, sprite_order, sprite_distance);
	SP_I = 0;
    while (SP_I < SP_NUM)
    {
		ft_calc_sprite(data, sprite_order, sprite_distance);
    	SP_W = abs((int)(SC_H / (SP_TRANSY)));
    	SP_DRSTARTX = -SP_W / 2 + SP_SCREENX;
    	if (SP_DRSTARTX < 0) SP_DRSTARTX = 0;
    	SP_DRAWENDX = SP_W / 2 + SP_SCREENX;
    	if(SP_DRAWENDX >= SC_W) SP_DRAWENDX = SC_W - 1;
		SP_STRIPE = SP_DRSTARTX;
    	while (SP_STRIPE < SP_DRAWENDX)
    	{
        	SP_TEX_X = (int)(256 * (SP_STRIPE - (-SP_W / 2 + SP_SCREENX)) * SP1_W / SP_W) / 256;
        	if (SP_TRANSY > 0 && SP_STRIPE > 0 && SP_STRIPE < SC_W && SP_TRANSY < Z_BUFF[SP_STRIPE])
			ft_draw_sprite_1(data);
			SP_STRIPE++;
    	}
		SP_I++;
    }
}

void	ft_order_sprite(t_data *data, int *sprite_order, double *sprite_distance)
{
	SP_I = 0;
	while (SP_I < SP_NUM)
    {
      sprite_order[SP_I] = SP_I;
      sprite_distance[SP_I] = ((PL_POSX - SP_ARRAY[SP_I][0]) * (PL_POSX - SP_ARRAY[SP_I][0]) + \
	   (PL_POSY - SP_ARRAY[SP_I][1]) * (PL_POSY - SP_ARRAY[SP_I][1]));
	  SP_I++;
    }
	ft_sort(sprite_order, sprite_distance, SP_NUM);
	ft_reverse(sprite_order, sprite_distance, SP_NUM);
}

void	ft_calc_sprite(t_data *data, int *sprite_order, double *sprite_distance)
{
      SP_SPX = SP_ARRAY[sprite_order[SP_I]][0] - PL_POSX;
      SP_SPY = SP_ARRAY[sprite_order[SP_I]][1] - PL_POSY;
      SP_INVDET = 1.0 / (PL_PLANEX * PL_DIRY - PL_DIRX * PL_PLANEY);
      SP_TRANSX = SP_INVDET * (PL_DIRY * SP_SPX - PL_DIRX * SP_SPY);
      SP_TRANSY = SP_INVDET * (-PL_PLANEY * SP_SPX + PL_PLANEX * SP_SPY);
      SP_SCREENX = (int)((SC_W / 2) * (1 + SP_TRANSX / SP_TRANSY));
      SP_H = abs((int)(SC_H / (SP_TRANSY)));
      SP_DRSTARTY = -SP_H / 2 + SC_H / 2;
      if (SP_DRSTARTY < 0) SP_DRSTARTY = 0;
      SP_DRAWENDY = SP_H / 2 + SC_H / 2;
      if (SP_DRAWENDY >= SC_H) SP_DRAWENDY = SC_H - 1;

}

void	ft_draw_sprite_1(t_data *data)
{
	t_color		color;

	SP_Y = SP_DRSTARTY;
	while (SP_Y < SP_DRAWENDY)
    {
    	SP_D = (SP_Y) * 256 - SC_H * 128 + SP_H * 128;
    	SP_TEX_Y = ((SP_D * SP1_H) / SP_H) / 256;
    	SP_COLORPIXEL = SP1_DATA[SP1_H * SP_TEX_Y + SP_TEX_X];
		if ((SP_COLORPIXEL & 0x00FFFFFF) != 0)
		{
			if (SCSHOT_DO == 1)
			{
				color = ft_int_to_rgb(SP_COLORPIXEL);
				SCSHOT_POS = (SP_Y * SC_W + SP_STRIPE) * 3;
				SCSHOT[SCSHOT_POS] = color.b;
				SCSHOT[SCSHOT_POS + 1] = color.g;
				SCSHOT[SCSHOT_POS + 2] = color.r;
			}
			my_mlx_pixel_put(data, SP_STRIPE, SP_Y, (SP_COLORPIXEL));
		}
		SP_Y++;
	}
}
