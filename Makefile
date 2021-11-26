##
## EPITECH PROJECT, 2021
## gameoflife
## File description:
## Makefile
##

CC		= gcc -W -Wall -Wextra

SRC		= $(wildcard *.c)

LIBSRC	= $(wildcard lib/my/*.c)

OBJ		= $(SRC:.c=.o)

LIBOBJ 	= $(LIBSRC:.c=.o)

OUT		= gol

LIB		= lib/libmy.a

all: $(OUT)

$(OUT): $(LIB) $(OBJ)
	$(CC) -o $@ $(OBJ) -Llib -lmy -lncurses

$(LIB): $(LIBOBJ)
	$(AR) rsc $@ $(LIBOBJ)

clean:
	$(RM) $(LIBOBJ)
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIB)
	$(RM) $(OUT)

re: fclean all
