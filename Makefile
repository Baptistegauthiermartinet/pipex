NAME = pipex
CC = cc -Wall -Wextra -Werror -g3
RM = rm -rf
SRC_PATH = ./src/
SRC_FILE = 	main.c\
			check_args.c\
			free.c\
			tools.c

SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ_PATH = ./obj/
OBJ_FILE = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILE))

INCLUDE_PATH = ./includes/
INCLUDE_FILE = pipex.h
INC = $(addprefix $(INCLUDE_PATH), $(INCLUDE_FILE))

LIBFT_PATH = ./libft/
LIBFT_FILE = libft.a
LIBFT_LIB = $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

all : lib $(NAME) 

$(NAME) : $(OBJ_PATH) $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB) -o $(NAME)

$(OBJ_PATH)%.o : %.c $(INC)
	mkdir -p $(shell dirname $@)
	$(CC) -c $< -o $@

${OBJ_PATH} :
	mkdir $(OBJ_PATH)

lib : 
	make -C $(LIBFT_PATH)

clean :
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJ_PATH)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re : fclean all

.PHONY : all clean fclean re