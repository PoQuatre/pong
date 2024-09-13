NAME = pong

# Source files

SRC = srcs/main.c \
	  srcs/ansi.c \
	  srcs/term.c \
	  srcs/term_utils.c

OBJ = $(SRC:.c=.o)

# Headers

INC = includes/

INC_PARAMS = $(INC:%=-I%)

# Compiler settings

CFLAGS += -Wall -Wextra -Werror

# Rules

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) $(INC_PARAMS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all
