NAME	= get_next_line.a

OBJ	= ${SRC:%.c=%.o}

OBJ_BONUS	= ${SRC_BONUS:%.c=%.o}

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

SRC	= get_next_line.c get_next_line_utils.c 

SRC_BONUS	= get_next_line_bonus.c get_next_line_utils_bonus.c

$(NAME)	: $(OBJ)
	ar rc $@ $?
	
bonus: $(OBJ) $(OBJ_BONUS)
	ar rc $(NAME) $(OBJ_BONUS) $(OBJ)

%.o: %c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
