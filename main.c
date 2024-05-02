/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:09:26 by mamerlin          #+#    #+#             */
/*   Updated: 2024/05/02 20:20:02 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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
	if (validation(matrix) != 1)
	{
		ft_close_matrix(matrix);
		return (write(1, "Error\n", 6));
	}
	stack_init(&stack_a, matrix);
	resolution(&stack_a, &stack_b, matrix);
	return (1);
}

void	final_rotate(int index, t_stack **a)
{
	int	i;

	i = -1;
	if (index <= (ft_lstsize(*a) / 2))
	{
		while (++i < (index - 1))
			ft_ra(a);
	}
	else
	{
		while (++i <= (ft_lstsize(*a) - index))
			ft_rra(a);
	}
	return ;
}

int	lowest_num(t_stack **a)
{
	t_stack	*tmp;
	int		index;
	int		num;

	tmp = (*a);
	num = tmp->nbr;
	ft_index(*a);
	while (tmp)
	{
		if (num > tmp->nbr)
		{
			index = tmp->index;
			num = tmp->nbr;
		}
		tmp = tmp->next;
	}
	final_rotate(index, a);
	return (num);
}

void	resolution(t_stack **a, t_stack **b, char **matrix)
{
	if (!check_if_sorted(*a))
		solve(a, b);
	if (!check_if_sorted(*a))
		lowest_num(a);
	ft_close_matrix(matrix);
	ft_close_stack(a);
	ft_close_stack(b);
	return ;
}
