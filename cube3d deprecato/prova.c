#include <mlx.h>
#include <stdio.h>

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct  s_vars {
    void        *mlx;       //pointer della memoria della libreria
    void        *win;       //pointer della memoria finestra
}               t_vars;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel) / 8);  // calcolo dell'offset della memoria usando la lunghezza della linea
    *(unsigned int*)dst = color;                                //mette il colore in dest
}

int            key_hook(int keycode, t_vars *vars)
{
    if (keycode == 53)          //se si preme esc esce dal programma
        //mlx_destroy_window(vars->mlx, vars->win);
        exit (0);
    if (keycode == 36)          //se si preme invio scrive testo
        printf("Hello from key_hook!\n");
    else
     return (0);
}

int             main(void)
{
    // void    *mlx;               //pointer della memoria della libreria
    // void    *mlx_win;           //pointer della memoria finestra
    t_data  img;                //struttura con info immagine
    t_vars  vars;               //struttura con variabili libreria

    int x = 200;
    int y = 200;
    
    vars.mlx = mlx_init();           //inizializzazione della memoria della libreria
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");      //creazione nuova finestra
    img.img = mlx_new_image(vars.mlx, 1920, 1080);                       //creazione nuova immagine
    /*
     Dopo aver creato un'immagine, possiamo chiamare `mlx_get_data_addr`, gli passiamo 
    `bits_per_pixel`, `line_length`, e `endian` di riferimento. Questi saranno poi
    settati secondo l'indirizzo corrente dei dati.
    */
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,        
                                 &img.endian);
    mlx_hook(vars.win, 2, 1L<<0, key_hook, &vars);      //evento, tasto premuto dall'utente 
    while (x < 500)
    {
        my_mlx_pixel_put(&img, x, y, 0x0000FFFF);                   //inserimento del pixel nell'immagine (immagine, x, y, colore)
        //mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);           //push dell'immagine nella finestra
        x++;
    }
    while (y < 500)
    {
        my_mlx_pixel_put(&img, x, y, 0x0000FFFF);                   //inserimento del pixel nell'immagine (immagine, x, y, colore)
        //mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);           //push dell'immagine nella finestra
        y++;
    }
    while (x > 200)
    {
        my_mlx_pixel_put(&img, x, y, 0x0000FFFF);                   //inserimento del pixel nell'immagine (immagine, x, y, colore)
        //mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);           //push dell'immagine nella finestra
        x--;
    }
    while (y > 200)
    {
        my_mlx_pixel_put(&img, x, y, 0x0000FFFF);                   //inserimento del pixel nell'immagine (immagine, x, y, colore)
        //mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);           //push dell'immagine nella finestra
        y--;
    }
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);           //push dell'immagine nella finestra
    mlx_loop(vars.mlx);                                                  //il loop serve a tenere la finestra aperta fino a comando di chiusura
}