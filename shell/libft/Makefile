#Name
NAME =			libft.a

#Compiler
CC = 			gcc
CFLAGS = 		-Wall -Wextra -Werror -g
CFLAG = 		-c
OFLAG =			-o
IFLAG =			-I		

#Ar
LIB =			ar -rcs

#Make
MAKE = 			make -C
MAKE_CLEAN = 	make clean -C
MAKE_FCLEAN = 	make fclean -C

#Norm
NORM = 			norminette

#Shell
MKDIR =			mkdir -p
CP =			cp
RM =			rm -rf

#Directories
SRCDIR = 		./srcs
OBJDIR =  		./objs
INCDIR = 		./incs
FPRINTFDIR = 	$(shell find $(SRCDIR) -name ft_fprintf)

#Libs
FPRINTF =		libftfprintf.a

#Files
FILES =			ft_strlen.c \
				ft_strcpy.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strnstr.c \
				ft_strncmp.c \
				ft_strcmp.c \
				ft_atoi.c \
				ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_swap.c \
				ft_dist.c \
				ft_isspace.c \
				ft_isspace_string.c \
				ft_isdigit_string.c \
				ft_mtxlen.c \
				ft_matrcpy.c \
				ft_if_free.c \
				ft_tabcpy.c \
				ft_if_free_mtx.c \
				ft_atol.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memccmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_strcharjoin.c \
				ft_strinsubs.c \
				ft_isescaped.c \
				ft_split_bash.c \
				ft_split_bash2.c \
				ft_split_bash3.c \
				ft_split_bash4.c \
				ft_jump_spaces.c \
				ft_jump_quotes_text.c \
				ft_strcmp_until.c \
				ft_bnessi_split.c \
				ft_putstr_fd.c \

#Srcs
SRCS = 			$(foreach FILE, $(FILES), $(shell find $(SRCDIR) -name $(FILE)))

#Objs
OBJS = 			$(patsubst $(SRCDIR)/%, $(OBJDIR)/%, $(SRCS:.c=.o))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) $(IFLAG) $(INCDIR) $(CFLAG) $(OFLAG) $@ $< 

all: $(NAME)

$(NAME): $(OBJS) $(FPRINTF)
	@$(LIB) $(NAME) $(OBJS)

$(FPRINTF):
	@$(MAKE) $(FPRINTFDIR)
	@$(CP) $(FPRINTFDIR)/$(FPRINTF) $(NAME)

norm:
	@$(NORM) $(SRCDIR)
	@$(NORM) $(INCDIR)

clean:
	@$(RM) $(OBJDIR) $(OBJS) $(LIBFT) 
	@$(MAKE_CLEAN) $(FPRINTFDIR)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE_FCLEAN) $(FPRINTFDIR)

re: fclean all

.PHONY: all norm clean fclean re
