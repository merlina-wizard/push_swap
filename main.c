/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:09:26 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/18 18:42:52 by mamerlin         ###   ########.fr       */
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
		printf("\t%ld\n", (stack->nbr));
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
	
	print_stack(stack_a);
	print_stack(stack_b);

	return (1);
}
