#ifndef DEFINE_H
# define DEFINE_H



# define SC_W data->screen_width
# define SC_H data->screen_height

# define Z_BUFF data->z_buffer

# define SP_ARRAY data->sprites
# define SP_W data->get_sprite.sprite_width
# define SP_H  data->get_sprite.sprite_height
# define SP_Y data->get_sprite.y
# define SP_D data->get_sprite.d
# define SP_NUM data->num_sprite
# define SP_DRSTARTX data->get_sprite.draw_start_x
# define SP_DRSTARTY data->get_sprite.draw_start_y
# define SP_DRAWENDX data->get_sprite.draw_end_x
# define SP_DRAWENDY data->get_sprite.draw_end_y
# define SP_STRIPE data->get_sprite.stripe
# define SP_SCREENX data->get_sprite.sprite_screen_x
# define SP_TRANSY data->get_sprite.transform_y
# define SP_TRANSX data->get_sprite.transform_x
# define SP_I data->get_sprite.i
# define SP_INVDET data->get_sprite.inv_det
# define SP_COLORPIXEL data->get_sprite.color_pixel
# define SP_SPX data->get_sprite.sprite_x
# define SP_SPY data->get_sprite.sprite_y
# define SP_TEX_X data->get_sprite.tex_x
# define SP_TEX_Y data->get_sprite.tex_y

# define SP1_W data->sprite_1.width
# define SP1_H data->sprite_1.height
# define SP1_DATA data->sprite_1.data

# define SCSHOT_POS data->position_screenshot
# define SCSHOT data->screenshot
# define SCSHOT_DO data->do_screenshot

# define PL_POSX data->player.posx
# define PL_POSY data->player.posy
# define PL_PLANEX data->player.planex
# define PL_PLANEY data->player.planey
# define PL_DIRY data->player.diry
# define PL_DIRX data->player.dirx

#endif