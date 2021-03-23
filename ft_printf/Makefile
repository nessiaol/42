

FLAGS = gcc  -c -Wall -Wextra -Werror

NAME = libftprintf.a

SRC = 	utils.c \
		utils_fillers.c \
		put_hexa.c \
		processor.c \
		process_un_integers.c \
		process_type.c \
		process_integers2.c \
		process_integers.c \
		process_hexa.c \
		printer.c \
		ft_printf.c \
		fill_struct.c \
		utils_fillers2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		$(FLAGS) $(SRC)		
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

clean:
		rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

bonus: $(OBJ) $(BONUS_OBJ)
		ar rc $(NAME) $(OBJ) $(BONUS_OBJ)

.PHONY: all clean fclean re bonus