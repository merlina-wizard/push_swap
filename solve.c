/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:31:29 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/17 13:18:49 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	solve(t_stack *a, t_stack *b)
{
	check_if_sorted(a);
	if (ft_lstsize(a) <= 3)
		sort_three(a);
	else if (b == NULL)
	{
		ft_pb(&a, &b);
		ft_pb(&a, &b);
	}
}

void	calculate_cost(t_stack *a)
{
	while (a != ft_lstlast(a))
		return ;
}

void	sort_three(t_stack *a)
{
	if (a->nbr > a->next->nbr)
		ft_sa(&a);
	print_stack(a);
	if (check_if_sorted(a))
	{
		printf("bho\n");
		printf("%i\n", check_if_sorted(a));
		return ;
	}
	ft_rra(&a);
	if (check_if_sorted(a))
		return ;
}

int	check_if_sorted(t_stack *stack)
{
	print_stack(stack);
	printf("......\n");
	while (stack->next)
	{
		if (stack->nbr < stack->next->nbr)
			stack = stack->next;
		else
		{
			printf("ci passi?\n");
			return (0);
		}
	}
	return (5);
}
