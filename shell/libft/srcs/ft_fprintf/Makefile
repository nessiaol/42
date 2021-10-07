#Name
NAME =			libftfprintf.a

#Compiler
CC = 			gcc
CFLAGS = 		-Wall -Wextra -Werror
CFLAG = 		-c
OFLAG =			-o
IFLAG =			-I

#Ar
LIB =			ar -rcs

#Shell
MKDIR =			mkdir -p
CP =			cp
RM =			rm -rf

#Directories
SRCDIR = 		./srcs
OBJDIR =  		./objs
INCDIR = 		./incs

#Files
FILES =			ft_fprintf.c \
				ft_modifiers.c \
				ft_spec_c.c \
				ft_spec_s.c \
				ft_spec_p.c \
				ft_spec_d.c \
				ft_spec_u.c \
				ft_spec_x.c \
				ft_spec_r.c \
				ft_isdigit_2.c \
				ft_numlen_base.c \
				ft_unumlen_base.c \
				ft_ulnumlen_base.c \
				ft_putchar_fd.c \
				ft_putnbr_base_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_putstrlen_fd.c \
				ft_putunbr_base_fd.c \
				ft_putunbr_fd.c \
				ft_special_atoi.c \
				ft_strlen_2.c

#Srcs
SRCS = 			$(foreach FILE, $(FILES), $(shell find $(SRCDIR) -name $(FILE)))

#Objs
OBJS = 			$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRCS:.c=.o))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) $(IFLAG) $(INCDIR) $(CFLAG) $(OFLAG) $@ $< 

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIB) $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJDIR) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
