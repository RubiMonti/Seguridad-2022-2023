CC = gcc

FLAGS = -Wshadow -Wall -g -lm

CAESAR = caesar

BREAK = breakcaesar

ALL = caesar_utils

SRC = $(addsuffix .c, $(ALL))

OBJS = 	$(addsuffix .o, $(ALL))

all: $(CAESAR) $(BREAK)

$(CAESAR):
	$(CC) $(FLAGS) -c $(SRC) $(CAESAR).c
	$(CC) -o $(CAESAR) $(OBJS) $(CAESAR).o

$(BREAK):
	$(CC) $(FLAGS) -c $(SRC) $(BREAK).c
	$(CC) -o $(BREAK) $(OBJS) $(BREAK).o

clean: 
	rm -f *.o

fclean: clean
	rm -f $(CAESAR)
	rm -f $(BREAK)

re: fclean all

.PHONY: clean fclean all re