CC = gcc

FLAGS = -Wshadow -Wall -g

NAME = caesar

ALL = caesar caesar_utils

SRC = $(addsuffix .c, $(ALL))

OBJS = 	$(addsuffix .o, $(ALL))

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) -o $(NAME) $(OBJS)

all: $(NAME)

clean: 
	rm -f *.o

fclean: clean
	rm -f $(NAME) *.gch

re: fclean all

.PHONY: clean fclean all re