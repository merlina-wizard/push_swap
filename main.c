/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:09:26 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/09 16:46:17 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
void print_stack(t_list *stack)
{
	t_list *tmp;

	tmp = stack;
    printf("Stack:\n");
    while (stack){
		printf("prev:[%p]", (stack->prev));
		printf(" current:[%p]", (stack));
		printf(" next[%p]", (stack->next));
        printf("\t%d\n", (stack->data));
        stack = stack->next;
		if (stack == tmp)
			break;
    }
}

int	main(int argc, char **argv)
{
	char	**matrix;
	t_list	*heada;
	t_list	*headb;
	t_stack	stucks;

	heada = NULL;
	headb = NULL;
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
	stack_init(&heada, matrix);
	stucks.heada = heada;
	stucks.headb = headb;
	sa(&stucks);
	print_stack(stucks.heada);
	return (1);
}
