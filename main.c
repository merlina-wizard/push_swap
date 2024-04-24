/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:09:26 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/25 00:54:36 by mamerlin         ###   ########.fr       */
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
	final_rotate(stack_a);
	print_stack(stack_a);
	print_stack(stack_b);
	(void)stack_b;
	return (1);
}

long	find_lowest(t_stack *list)
{
	t_stack	*tmp;
	int		ret;

	tmp = list;
	ret = tmp->nbr;
	while (tmp)
	{
		if (ret > tmp->nbr)
			ret = tmp->nbr;
		tmp = tmp->next;
	}
	return (ret);
}
void	final_rotate(t_stack *a)
{
	long	low;
	t_stack	*tmp;

	tmp = a;
	low = find_lowest(a);
	while (tmp)
	{
		if (tmp->nbr == low)
			return ;
		if ((a)->index <= ft_lstsize(a) / 2)
			ft_ra(&a);
		else
			ft_rra(&a);
		tmp = a;
	}
	return ;
}
