NAME		=	push_swap

SRC			= main.c utils.c utils2.c utilss33.c list.c validation.c close.c \

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
