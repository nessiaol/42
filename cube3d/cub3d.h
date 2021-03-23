#ifndef CUB3D_H
#define CUB3D_H
# define BUFFER_SIZE 1
# define PIXEL_SIZE 32
# define PNG_SIZE 4

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
//# include "libraries/libft/libft.h"
# include "libraries/minilibx/mlx.h"

typedef struct  s_img {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_img;

typedef struct	s_keys {
	int			w;
	int			a;
	int			s;
	int			d;
	int			esc;
}				t_keys;

typedef struct	s_direction {
	int			north;
	int			south;
	int			west;
	int			east;
}				t_direction;

typedef struct s_png {
	int			px;
	int			py;
}				t_png;


typedef struct  s_map {
    int         res_x;
    int         res_y;
    char        *north_texture;
    char        *south_texture;
    char        *west_texture;
    char        *east_texture;
    char        *sprite_texture;
    int         f_red;
    int         f_green;
    int         f_blue;
	int         c_red;
    int         c_green;
    int         c_blue;
	int			color_floor;
	int			color_ceiling;
	// int			start_x;
	// int			start_y;
	//int			written_pixel;
	//int			map_size_y;
	//int			map_start;
	char		**map_matrix;
}               t_map;

typedef struct  s_mlx {
    void        *mlx;
    void        *win;
}               t_mlx;

typedef	struct	    s_list {
	char			*content;
	struct s_list	*next;
}					t_list;

typedef	struct	s_all {
	t_img		img;					
	t_map		map;
	t_mlx		mlx;
	t_direction	direction;
	t_keys		keys;
	t_png		png;
}				t_all;

int            	key_hook(int keycode, t_all *all);
void			ft_draw(t_all *all, t_list *list);
void			ft_init_window(t_all *all);
int             main(int argc, char **argv);

size_t	        ft_strlen(const char *s);
char	        *ft_strchr_get(char *str, int n);
char	        *ft_strjoin(const char *src, const char *dst);
char	        *ft_strdup(const char *str);
char	        *ft_substr_get(char *str, size_t start, size_t len);
char	        *joinbuffer(char *current, char *buf);

char	        *get_newline(char *current, char **line, int read_res);
int		        get_next_line(int fd, char **line);
t_list	        *ft_lstnew(void *content);
void	        ft_lstadd_back(t_list **lst, t_list *new);
t_list	        *ft_lstlast(t_list *lst);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_lstsize(t_list *lst);

void            my_mlx_pixel_put(t_all *all, int x, int y, int color);
void        	ft_draw_line(t_all *all, int x, int y, int i);
void        	draw_pixel_size(t_all *all, int x, int y, int color);
void			ft_check_start_dir(t_all *all, char c);
void			ft_draw_png(t_all *all, int x, int y, int color);

t_list			*ft_check_options(int fd, t_all *all, t_list *list);
void			ft_check_map(int fd, t_list *list);
void			ft_line_parsing_one(t_all *all, t_list *list);
void			ft_parse_textures(t_all *all, t_list *list);
void			ft_floor_color(t_all *all, t_list *list);
void			ft_ceiling_color(t_all *all, t_list *list);
int				create_trgb(int t, int r, int g, int b);

void			ft_init_direction(t_all *all);
void			ft_init_keys(t_all *all);

void			ft_list_to_matrix(t_all *all, t_list *list);
void			ft_draw_minimap(t_all *all);


void			ft_draw_visual_line(t_all *all, int color);

# endif