# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-luca <bde-luca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/06 16:27:37 by dmangola          #+#    #+#              #
#    Updated: 2021/10/01 12:05:56 by bde-luca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME =				minishell

#Compiler
CC = 				gcc
CFLAGS = 			-Wall -Wextra -Werror -g
CFLAG = 			-c
OFLAG =				-o
IFLAG =				-I
TCFLAG =			-ltermcap

#Make
MAKE = 				make -C
MAKE_CLEAN = 		make clean -C
MAKE_FCLEAN = 		make fclean -C
MAKE_NORM =			make norm -C

#Norm
NORM =				norminette

#Shell
MKDIR =				mkdir -p
CP =				cp
RM =				rm -rf

#Directories
SRCDIR = 			./srcs
OBJDIR =  			./objs
INCDIR = 			./includes
LIBFTDIR = 			./libft

LIBFT = 			libft.a

FILES =				main.c \
					ft_pwd.c \
					graphic.c \
					ft_echo.c \
					ft_cd.c \
					find_index_pos.c \
					ft_init.c \
					parser.c \
					parser_files.c \
					redirection.c \

SRCS =	$(foreach FILE, $(FILES), $(shell find $(SRCDIR) -name $(FILE)))

OBJS =	$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRCS:.c=.o))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) $(IFLAG) $(INCDIR) $(CFLAG) $(OFLAG) $@ $< 

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(TCFLAG) $(OBJS) $(LIBFT) $(OFLAG) $(NAME) -lreadline 

$(LIBFT):
	@$(MAKE) $(LIBFTDIR)
	@$(CP) $(LIBFTDIR)/$(LIBFT) .

norm:
	@$(NORM) $(SRCDIR)
	@$(NORM) $(INCDIR)
	@$(MAKE_NORM) $(LIBFTDIR)

clean:
	@$(RM) $(OBJDIR) $(OBJS) $(LIBFT) 
	@$(MAKE_CLEAN) $(LIBFTDIR)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE_FCLEAN) $(LIBFTDIR)

re: fclean all

.PHONY: all norm clean fclean re
