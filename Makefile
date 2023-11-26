SRCS = main.c solve.c check_row_left.c check_row_right.c backtrack.c generate_outcomes.c check.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

NAME = solve

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) && ./solve

all: $(NAME)

clean:
	rm -rf $(OBJS) ./solve

fclean: clean
	rm -rf $(NAME)

re: fclean all
