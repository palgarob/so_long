# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pepaloma <pepaloma@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/10 16:37:25 by pepaloma          #+#    #+#              #
#    Updated: 2023/12/11 17:44:02 by pepaloma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX_DIR		= minilibx_opengl_20191021
LIBFT_DIR	= libft
SRC_DIR		= src
OBJ_DIR		= obj
BIN_DIR		= bin

NAME		= $(BIN_DIR)/so_long

CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -rf
MLX_LINK_FLAGS	= -I $(MLX_DIR) -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
LIBFT_LINK_FLAGS= -I $(LIBFT_DIR) -L $(LIBFT_DIR) -lft
VALGRIND_FLAGS = -O0 -g

FILES	= $(notdir $(wildcard src/*.c))
SRC		= $(addprefix $(SRC_DIR)/, $(FILES))
OBJ		= $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

.PHONY : all re clean fclean
#.SILENT :

all : $(NAME)

$(NAME) : $(OBJ)
	@$(MAKE) -C $(MLX_DIR)
	@$(MAKE) -C $(LIBFT_DIR)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(LIBFT_LINK_FLAGS) $(MLX_LINK_FLAGS) $(VALGRIND_FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(VALGRIND_FLAGS) -c $< -o $@

re : fclean all

fclean : clean
	$(RM) $(BIN_DIR)
	$(MAKE) -C $(LIBFT_DIR) fclean

clean :
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
