##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## Makefile
##

#flag#

CFLAGS = -Wall -Wextra -Werror -Wshadow

CPPFLAGS = -iquote $(IDIR)

DBGFLAGS = -g3 -ggdb

LDFLAGS =

LIBFLAGS = -L lib/ -lmy

#source#

SRC = $(wildcard ./src/*.c && ./main.c)

OBJ = $(SRC:.c=.o)

NAME = bsq

IDIR = ./include

CC = gcc

RM = rm -f

#rules#

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(LIBFLAGS)
	rm -f $(OBJ)

debug: CFLAGS += $(DBGFLAGS)
debug: $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) include/*.gc*
	$(RM) vgcore*

fclean: clean
	$(RM) $(NAME)
	$(RM) a.out

re: fclean all

lib:
	make -C lib/my

.PHONY: fclean clean re all debug lib

tests_run: LDFLAGS += -lcriterion --coverage

tests_run:
		$(CC) -o unit_tests tests/project.c $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)
		./unit_tests
		gcovr -e tests/
