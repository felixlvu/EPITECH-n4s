##
## EPITECH PROJECT, 2021
## N4S Louis Huget
## File description:
## Makefile
##

SRC =	src/main.c\
		src/start_n4s.c\
		src/mouv_manage.c\
		src/turn_right_left.c\

NAME = ai

CFLAGS = -Iinclude -W -Wall -Wextra -g3

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

debug: CFLAGS += -g3
debug: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all
