NAME	= get_next_line.a

OBJ	= ${SRC:%.c=%.o}

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

SRC	= get_next_line.c get_next_line_utils.c

$(NAME)	: $(OBJ)
	ar rc $@ $?

%.o: %c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
