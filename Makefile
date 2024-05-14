# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tanselmo <tanselmo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 16:53:03 by tanselmo          #+#    #+#              #
#    Updated: 2024/05/10 17:09:44 by tanselmo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

USER = tanselmo

NAME = so_long

CC = gcc

CFLAGS = -Wextra -Wall -Werror -g

MLX42 = ./MLX42

LIBFT = ./Libft

SRC_DIR = src/

OBJ_DIR = obj/

SRC_FILES = main \
check \
flood_fill \
init_game \
items \
map \
utils \
textures \
moves \
mov \

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(NAME):    $(OBJ)
	@make -s all bonus printf gnl -C $(LIBFT)
	@make -C $(MLX42)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -L$(MLX42) -lmlx42 -framework Cocoa -framework OpenGL -framework IOKit -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -frf $(OBJ_DIR)
	@make clean -C $(MLX42)
	@make -s -C $(LIBFT) clean

fclean:
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@make fclean -C $(MLX42)
	@make -s -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re