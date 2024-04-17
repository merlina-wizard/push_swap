/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:31:29 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/17 11:42:15 by mamerlin         ###   ########.fr       */
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
		pb(&a);
		pb(&a);
	}
	calculate_cost(&a, &b);
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	while (a != ft_lstlast(&a))
	{


	}
}
void	sort_three(t_stack *a)
{
	while(!check_if_sorted)
	{
		if (a->nbr > a->next->nbr)
			sa(a);
		if (check_if_sorted(a))
			return ;
	}


}

int	check_if_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->nbr < stack->next->nbr)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}
