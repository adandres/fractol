# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adandres <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/15 19:02:41 by adandres          #+#    #+#              #
#    Updated: 2018/12/26 16:26:58 by adandres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc -c
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
SRC = ft_strsplit_to_lst.c ft_list_push_tab.c ft_print_list.c ft_add_link.c ft_list_reverse.c ft_list_push_params.c ft_lstmap.c ft_lstiter.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstnew.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_tolower.c ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c ft_isalpha.c ft_strsub.c ft_strnequ.c ft_strequ.c ft_strmapi.c ft_strmap.c ft_itoa.c ft_striteri.c ft_striter.c ft_atoi.c ft_strncmp.c ft_strcmp.c ft_strnstr.c ft_strstr.c ft_strrchr.c ft_strchr.c ft_strlcat.c ft_strncat.c ft_strcat.c ft_strncpy.c ft_strcpy.c ft_strdup.c ft_putendl.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr.c ft_putchar_fd.c ft_strlen.c ft_memcmp.c ft_memchr.c ft_memmove.c ft_memccpy.c ft_memcpy.c ft_memdel.c ft_strnew.c ft_putchar.c ft_putstr.c ft_bzero.c ft_memset.c ft_memalloc.c ft_strdel.c ft_strclr.c ft_putnbr_fd.c
all : $(NAME)

$(NAME) :
		$(CC) $(FLAGS) $(SRC)
		ar rc $@ $(OBJ)
		ranlib $(NAME)

clean :
	    rm -f $(OBJ)

fclean : clean
	    rm -f $(NAME)

re : fclean all
