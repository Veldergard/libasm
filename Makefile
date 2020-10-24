NAME = libasm.a

NA = nasm

NFLAGS = -f macho64

SRC = ft_read.s \
	ft_write.s \
	ft_strcmp.s \
	ft_strlen.s \
	ft_strcpy.s \
	ft_strdup.s \

OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $^
	ranlib $(NAME)

%.o: %.s
	$(NA) $(NFLAGS) $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: fclean
	gcc -L. -lasm -o test main.c
	./test

.PHONY: all re clean fclean test