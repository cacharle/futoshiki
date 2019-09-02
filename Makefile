NAME = futoshiki
CC = gcc
CCFLAGS = -Wall -Wextra
LDFLAGS =

HEADER = futo.h
SRC = main.c futo.c square.c
OBJ = $(SRC:.c=.o)

RM = rm -f

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(LDFLAGS) $(CCFLAGS) -o $@ $(OBJ)

%.o: %.c
	$(CC) $(LDFLAGS) $(CCFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all
