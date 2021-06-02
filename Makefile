# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adandres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/27 02:42:08 by adandres          #+#    #+#              #
#    Updated: 2019/01/23 17:19:06 by adandres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -D_REENTRANT -Wall -Wextra -Werror
NAME = fractol
INCLUDES = -I /usr/local/include -I src/fat.h
LIBS = libft/libft.a -L /usr/X11/lib/ -lmlx -lpthread -framework OpenGL \
	   -framework AppKit
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
	$(MAKE) -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_FILES) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC)/%.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

clean :
	$(MAKE) -C libft $@
	rm -rf $(OBJ_DIR)

fclean : clean
	$(MAKE) -C libft $@
	rm -f $(NAME)

re : fclean all
	$(MAKE) -C libft $@
