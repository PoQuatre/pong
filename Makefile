NAME = pong

# Source files

SRC = srcs/main.c \
	  srcs/game.c \
	  srcs/draw_utils.c \
	  srcs/ansi.c \
	  srcs/errors.c \
	  srcs/term_utils.c \
	  srcs/timer.c \
	  srcs/libft/ft_getchar.c \
	  srcs/libft/ft_strlen.c \
	  srcs/libft/ft_putstr.c \
	  srcs/libft/ft_putstr_err.c \
	  srcs/libft/ft_putnbr.c \
	  srcs/libft/ft_putnbr_err.c \
	  srcs/libft/ft_itoa.c \
	  srcs/libft/ft_strrev.c \
	  srcs/libft/ft_strcat.c \

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

.PHONY: run
run: all
	./$(NAME)

.PHONY: rerun
rerun: re
	./$(NAME)
