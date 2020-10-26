# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/26 16:36:41 by olaurine          #+#    #+#              #
#    Updated: 2020/10/26 17:34:36 by olaurine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a
NA = nasm
NFLAGS = -f macho64
SRC = ft_read.s \
	ft_write.s \
	ft_strcmp.s \
	ft_strlen.s \
	ft_strcpy.s \
	ft_strdup.s
OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	echo $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.s
	$(NA) $(NFLAGS) $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: re
	gcc -L. -lasm -o test main.c
	./test

.PHONY: all re clean fclean test
