#ifndef PS_H
# define PS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}				t_list;

typedef struct s_stack
{
	t_list	*heada;
	t_list	*headb;
}				t_stack;

char			**mat(int argc, char **argv);
char			**ft_split(char const *s, char c);
long long		ft_atoi(const char *str);
char			**mat(int argc, char **argv);
int				validation(char **mat);
int				isnum(char *save);
int				michael_buble(char **mat);
int				ft_close_matrix(char **matrix);
char			*ft_strdup(const char *src);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
t_list			*ft_lstnew(int data);
int				stack_init(t_list **a, char **mat);
int				create(t_list **list, char	*mat);
int				sa(t_stack *a);
int				sb(t_stack *a);

#endif
