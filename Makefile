GREEN = /bin/echo -e "\x1b[1;3;32m$1\x1b[0m"
CC = gcc -g
CFLAGS = -Wall -Werror -Wextra 
SRC =	srcs/ft_parce_input.c \
	srcs/ft_check_meta.c \
	srcs/ft_split_cmd.c \

OBJ = $(SRC:.c=.o)
NAME = minishell
LIB = libft/libft.a

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C ./libft
		$(CC) $(CFLAGS) $(OBJ) $(LIB) -lreadline -o $@
		$(call GREEN,"Compilation success 😁")

clean:
		make clean -C ./libft
		rm -f $(OBJ)
		$(call GREEN,"The .o cleaned up !")

fclean:		clean
		make fclean -C ./libft
		rm -f $(NAME)
		$(call GREEN,"The rest too !")

re:		fclean all

.SILENT:
.PHONY:		all clean fclean re 
