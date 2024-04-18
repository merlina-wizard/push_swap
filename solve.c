/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:31:29 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/18 18:43:41 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	solve(t_stack **a, t_stack **b)
{
	if (check_if_sorted(*a))
		return ;
	while (ft_lstsize(*a) > 3)
	{
		if (b == NULL)
		{
			ft_pb(a, b);
			ft_pb(a, b);
		}
		target_a(*a, *b);
	}
	if (ft_lstsize(*a) <= 3)
		mini_sort(a);
}

t_stack	*target_a(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*ret_a;
	t_stack	*head_a;
	int		tmp_cost;

	head_a = a;
	tmp_cost = INT_MAX;
	while (a != ft_lstlast(a))
	{
		target = find_target(b, a->nbr);
		if (find_cost(head_a, a, b, target) < tmp_cost)
		{
			tmp_cost = find_cost(head_a, a, b, target);
			ret_a = a;
		}
	}
	return (ret_a);
}

int	find_cost(t_stack *a, t_stack *target_a, t_stack *b, t_stack *target_b)
{
	int	i;

	ft_index(a);
	ft_index(b);
	if (case() == 1)
		
	if (case() == 2)

}

int	case(target)
