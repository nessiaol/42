#include "cub3d.h"

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel) / 8);
    *(unsigned int*)dst = color;
}

// void        draw_pixel_size(t_data *img, int x, int y, int color)
// {
//     while (y < (y + PIXEL_SIZE))
//     {
//         while (x < (x + PIXEL_SIZE))
//         {
//             //printf("%d", PIXEL_SIZE);
//             my_mlx_pixel_put(img, x, y, color);                   
//             x++;
//         }
//         y++;
//     }
// }

void        ft_draw_line(t_list *list, t_data *img, int x, int y)
{
    int i;

    i = 0;
    //draw_pixel_size (img, x, y, 0x0000FFFF);
    while(list->content[i])
    {
        if (list->content[i] == '1')
        {
            //draw_pixel_size (img, x, y, 0x0000FFFF);
            my_mlx_pixel_put(img, x, y, 0x0000FFFF);
            x++;
        }
        else if (list->content[i] == '0')
        {
            x++;
        }
        i++;
        //y++;
    }
}



int            key_hook(int keycode, t_vars *vars)
{
    if (keycode == 53)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        exit (0);
    }
else if (keycode == 36)
        printf("Hello from key_hook!\n");
    return (0);
}

int             main(int argc, char **argv)
{
    t_data  img;
    t_vars  vars;
    t_list  *list;
    int x = 200;
    int y = 200;
    int lines;
	int fd;
	//int i = 0;
	char *line;
    

	printf("argc: %d\n", argc);
    
    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Map");
    img.img = mlx_new_image(vars.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,      
                                 &img.endian);
	mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);
	if (!(fd = open(argv[1], O_RDONLY)))
		return (-1);
    list = ft_lstnew("");
	while ((lines = get_next_line(fd, &line)) > 0)
	{
        ft_lstadd_back(&list, ft_lstnew(line));
        printf("list element: (%s)\n", list->content);
        //putpixel
        ft_draw_line(list, &img, x, y);
        list = list->next;
        //i++;
        y++;
    }
    ft_lstadd_back(&list, ft_lstnew(line));
    ft_draw_line(list, &img, x, y);
    list = list->next;
    printf("list element: (%s)\n", list->content);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_loop(vars.mlx);
}