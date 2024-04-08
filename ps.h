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
}				t_list;

char	**mat(int argc, char **argv);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	**mat(int argc, char **argv);
int		validation(char **mat);
int		isnum(char *save);
int		michael_buble(char **mat);
int		ft_close_matrix(char **matrix);
char	*ft_strdup(const char *src);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int data);

#endif
