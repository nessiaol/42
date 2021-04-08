
FLAGS = gcc -Wall -Wextra -Werror

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

NAME = cub3d.a

UTILS = ./utils/get_next_line.c \
		./utils/get_next_line_utils.c \
		./utils/ft_lstadd_back.c \
		./utils/ft_lstnew.c \
		./utils/ft_lstlast.c \
		./utils/ft_atoi.c \
		./utils/ft_isdigit.c \
		./utils/ft_substr.c \
		./utils/ft_lstsize.c \
		./utils/ft_itoa.c \

SRC = 	main.c \
		read_map.c \
		parse_map.c \
		draw_map.c \
		initializer.c \
		visual.c \
		call_map.c \
		keys.c \
		draw_raycasting.c \
		keypress.c \
		

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	$(FLAGS) $(MLX_FLAGS) $(SRC) $(UTILS) cub3d.h
	#gcc nuovo.c libmlx.a cub3d.h -framework OpenGL -framework Appkit

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re