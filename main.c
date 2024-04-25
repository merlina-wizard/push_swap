/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:09:26 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/25 18:41:36 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void print_stack(t_stack *stack)
{
    printf("Stack:\n");
    while (stack){
		// printf("prev:[%p]", (stack->prev));
		// printf(" current:[%p]", (stack));
		// printf(" next[%p]", (stack->next));
		printf("\t%ld and \t%ld\n", (stack->nbr), (stack->index));
		stack = stack->next;
    }
}

int	main(int argc, char **argv)
{
	char	**matrix;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	matrix = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		matrix = ft_split(argv[1], ' ');
	if (argc > 2)
		matrix = mat(argc, argv + 1);
	if (!validation(matrix))
	{
		ft_close_matrix(matrix);
		return (1);
	}
	stack_init(&stack_a, matrix);
	solve(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	final_rotate(&stack_a);
	print_stack(stack_a);
	print_stack(stack_b);
	(void)stack_b;
	return (1);
}

t_stack	*find_lowest(t_stack *list)
{
	t_stack	*tmp;
	t_stack	*ret;

	tmp = list;
	ret = tmp;
	while (tmp)
	{
		if (ret->nbr > tmp->nbr)
			ret->nbr = tmp->nbr;
		tmp = tmp->next;
	}
	return (ret);
}

void	final_rotate(t_stack **a)
{
	t_stack	*low;
	t_stack	*head;
	int		i;
	i = -1;
	head = (*a);
	head->nbr = (*a)->nbr;
	low = find_lowest(*a);
	(*a)->nbr = head->nbr;
	(*a) = head;
	ft_index(*a);
	if (low->index <= (ft_lstsize(*a) / 2))
	{
		while (++i < low->index)
			ft_ra(a);
	}
	else
	{
		while (++i < (ft_lstsize(*a) - low->index))
			ft_rra(a);
	}
}
