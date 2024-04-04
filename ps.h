#ifndef PS_H
# define PS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

int		isnum(char *save);
int		validate(int argc, char **argv);
char	**ft_split(char const *s, char c);
t_list	*lstnew(int content, t_list *pre);

typedef struct s_list
{
	int	content;
	t_list	*next;
	t_list	*prev;

}	t_list;

typedef struct s_stack
{
	t_stack		a;
	t_stack		b;
	t_list	*head;
	int		size;
}	t_stack;

#endif
