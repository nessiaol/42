NAME_CK = checker
NAME_PS = push_swap

LIBFT = libft.a

DIR_SRCS = srcs
DIR_CHECKER = checker
DIR_PUSH_SWAP = push_swap
DIR_UTILS = utils

SRCS_CHECKER = 	checker.c
SRCS_PUSH_SWAP =	push_swap.c
SRCS_UTILS = 	ft_atoi.c \
				ft_isdigit.c\

CHECKER_PREFIX = $(addprefix ${DIR_CHECKER}/, ${SRCS_CHECKER})
PUSH_SWAP_PREFIX = $(addprefix ${DIR_PUSH_SWAP}/, ${SRCS_PUSH_SWAP})
UTILS_PREFIX = $(addprefix ${DIR_UTILS}/, $(SRCS_UTILS))

SRCS_CHECKER_PREFIX = $(addprefix ${DIR_SRCS}/, ${CHECKER_PREFIX})
SRCS_PUSH_SWAP_PREFIX = $(addprefix ${DIR_SRCS}/, ${PUSH_SWAP_PREFIX})
SRCS_UTILS_PREFIX = $(addprefix ${DIR_SRCS}/, $(UTILS_PREFIX))

OBJS_CHECKER = $(SRCS_CHECKER_PREFIX:.c=.o)
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP_PREFIX:.c=.o)
OBJS_UTILS = $(SRCS_UTILS_PREFIX:.c=.o)

all: $(NAME_CK) $(NAME_PS)

.o.c: gcc -Wall -Wextra -Werror $<

$(NAME_CK): $(OBJS_CHECKER) $(OBJS_UTILS) $(LIBFT)
	gcc -Wall -Wextra -Werror -g $(OBJS_CHECKER) $(OBJS_UTILS) $(LIBFT) -o $(NAME_CK)

$(NAME_PS): $(OBJS_PUSH_SWAP) $(OBJS_UTILS) $(LIBFT)
	gcc -Wall -Wextra -Werror -g $(OBJS_PUSH_SWAP) $(OBJS_UTILS) $(LIBFT) -o $(NAME_PS)

$(LIBFT):
	make -C ./libft
	cp ./libft/$(LIBFT) .

clean:
	rm -rf $(OBJS_CHECKER) $(OBJS_PUSH_SWAP) $(OBJS_UTILS) $(LIBFT)
	make clean -C libft
fclean: clean
	rm -rf $(NAME_CK) $(NAME_PS)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
