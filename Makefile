NAME = pong

# Source files

SRC = srcs/main.c \
	  srcs/ansi.c \
	  srcs/term_utils.c \
	  srcs/timer.c \
	  srcs/libft/ft_getchar.c \

IS_UNIX := $(shell echo | $(CC) -dM -E - | grep -E '_WIN32')
ifeq ($(IS_UNIX),)
	SRC += srcs/term_unix.c
else
	SRC += srcs/term_windows.c
endif

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
	rm -f $(NAME) $(NAME).exe

.PHONY: re
re: fclean all
