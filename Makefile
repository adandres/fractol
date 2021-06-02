# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                        /       \.'`  `',.--//    #
#                                                     +:+ +:+         +:+      #
#    By: adandres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/27 02:42:08 by adandres          #+#    #+#              #
#    Updated: 2021/06/02 14:21:42 by adandres                                  #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -D_REENTRANT -Wall -Wextra -Werror
NAME = fractol
INCLUDES = -I src/fat.h -I minilibx_macos/
LIBS = libft/libft.a -lpthread -framework OpenGL -framework AppKit
DEPS = src/fat.h
SRC = src
SRC_FILES = $(SRC)/basic_fract.c $(SRC)/deal_fract.c $(SRC)/deal_input.c \
			$(SRC)/deal_mouse.c $(SRC)/fract.c $(SRC)/init_col.c \
			$(SRC)/init_fract.c $(SRC)/input.c $(SRC)/main.c $(SRC)/rgb.c \
			$(SRC)/print_celtic.c $(SRC)/print_julia.c $(SRC)/print_mandel.c \
			$(SRC)/print_ship.c $(SRC)/user_color.c $(SRC)/user_color2.c
OBJ_DIR = obj
OBJ_FILES = $(patsubst $(SRC)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

all : $(OBJ_DIR) $(NAME)

$(NAME) : $(OBJ_FILES)
	@make -C libft
	@make -C minilibx_macos
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBS) minilibx_macos/libmlx.a

$(OBJ_DIR)/%.o: $(SRC)/%.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

clean :
	@make -C libft clean
	@make -C minilibx_macos clean
	rm -rf $(OBJ_DIR)

fclean : clean
	@make -C libft fclean
	@make -C minilibx_macos clean
	rm -f $(NAME)

re : fclean all
