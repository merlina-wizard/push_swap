/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:27:56 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/18 15:14:22 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

char			**mat(int argc, char **argv);
char			**ft_split(char const *s, char c);
long long		ft_atoi(const char *str);
char			**mat(int argc, char **argv);
int				validation(char **mat);
int				isnum(char *save);
int				michael_buble(char **mat);
int				ft_close_matrix(char **matrix);
char			*ft_strdup(const char *src);
void			ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack			*ft_lstlast(t_stack *lst);
void			ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack			*ft_lstnew(int data);
int				stack_init(t_stack **a, char **mat);
int				create(t_stack **list, char	*mat);
void			ft_pa(t_stack **a, t_stack **b);
void			ft_pb(t_stack **a, t_stack **b);
void			ft_ra(t_stack **a);
void			ft_rb(t_stack **b);
void			ft_rr(t_stack **a, t_stack **b);
void			ft_sa(t_stack **a);
void			ft_sb(t_stack **b);
void			ft_ss(t_stack **a, t_stack **b);
void			ft_rra(t_stack **a);
void			ft_rrb(t_stack **b);
void			ft_rrr(t_stack **a, t_stack **b);
void			fake_ra(t_stack *a);
void			ft_index(t_stack *stack);
int				ft_lstsize(t_stack *lst);
void			solve(t_stack **a, t_stack **b);
int				check_if_sorted(t_stack *stack);
void			sort_three(t_stack **a);
void			print_stack(t_stack *stack);
void			mini_sort(t_stack **a);
t_stack			*target_a(t_stack *a, t_stack *b);
t_stack			*find_target(t_stack *stacks, int target);

#endif
