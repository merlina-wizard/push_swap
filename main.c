/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:09:26 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/27 19:27:34 by mamerlin         ###   ########.fr       */
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
	final_rotate(stack_a);
	print_stack(stack_a);
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

void	final_rotate(t_stack *a)
{
	t_stack	*tmp;
	int	index;
	int	num;
	int		i;

	i = -1;
	tmp = a;
	num = tmp->nbr;
	ft_index(a);
	while (tmp)
	{
		print_stack(a);
		if (num > tmp->nbr)
		{
			index = tmp->index;
			num = tmp->nbr;
		}
		print_stack(a);
		tmp = tmp->next;
	}
	if (index <= (ft_lstsize(a) / 2))
	{
		while (++i < index)
			ft_ra(&a);
	}
	else
	{
		while (++i <= (ft_lstsize(a) - index))
		{
			ft_rra(&a);
			print_stack(a);
		}
		print_stack(a);
	}
	return ;
}
