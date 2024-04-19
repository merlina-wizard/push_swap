NAME		=	push_swap

SRC			= main.c close.c final_move.c init.c list_utils.c mini_sort.c rotation.c rules_a.c rules_b.c simulation.c solve.c target.c utils.c utils2.c validation.c\

OBJ			=	$(SRC:.c=.o)

CC			=	gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all:		$(NAME)

git:
	git add .
	git commit -m "update"
	git push

clean:
			${RM} $(OBJ)

fclean: 	clean
			${RM} $(NAME) ${OBJ}

.PHONY:		all clean fclean re
