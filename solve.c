/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:31:29 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/28 13:20:02 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	solve(t_stack **a, t_stack **b)
{
	t_stack	*targeta;
	t_stack	*targetb;

	if (check_if_sorted(*a))
		return ;
	if (ft_lstsize(*a) <= 3)
	{
		mini_sort(a, b);
		return ;
	}
	while (*a)
	{
		if (ft_lstsize(*b) <= 0)
		{
			ft_pb(a, b);
			ft_pb(a, b);
		}
		ft_index(*a);
		ft_index(*b);
		targeta = target_a(*a, *b);
		targetb = find_target(*b, targeta->nbr);
		ft_cases(a, targeta, b, targetb);
		ft_pb(a, b);
	}
	while (*b)
		ft_pa(a, b);
	if (check_if_sorted(*a))
		return ;
}

t_stack	*target_a(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*ret_a;
	int		tmp_cost;
	int		cost;

	tmp_cost = INT_MAX;
	while (a)
	{
		target = find_target(b, a->nbr);
		a->cases = ft_case(a, target, ft_lstsize(a), ft_lstsize(b));
		cost = find_cost(a, a->index, target->index, b);
		if (cost < tmp_cost)
		{
			a->cases = ft_case(a, target, ft_lstsize(a), ft_lstsize(b));
			tmp_cost = cost;
			ret_a = a;
		}
		a = a->next;
	}
	return (ret_a);
}

void	ft_index(t_stack *stack)
{
	long	i;
	t_stack	*stack_head;

	stack_head = stack;
	i = 1;
	while (stack)
	{
		(stack)->index = i;
		stack = (stack)->next;
		i++;
	}
	stack = stack_head;
}

int	find_cost(t_stack *a, int index_a, int index_b, t_stack *b)
{
	int	i;

	if (a->cases == 1)
	{
		if ((ft_lstsize(a) - index_a) >= (ft_lstsize(b) - index_b))
			i = (ft_lstsize(a) - index_a) + 1;
		else
			i = (ft_lstsize(b) - index_b) + 1;
	}
	else if (a->cases == 2)
	{
		if (index_a > index_b)
			i = index_a - 1;
		else
			i = index_b - 1;
	}
	else if (a->cases == 3)
	{
		i = (index_a - 1) + (ft_lstsize(b) - index_b);
	}
	else
	{
		i = (index_b - 1) + (ft_lstsize(a) - index_a);
	}
	return (i);
}

int	ft_case(t_stack *target_a, t_stack *target_b, long max_a, long max_b)
{
	if (target_a->index >= (max_a / 2) && target_b->index >= (max_b / 2))
		return (1);
	if (target_a->index < (max_a / 2) && target_b->index < (max_b / 2))
		return (2);
	if (target_a->index <= (max_a / 2) && target_b->index >= (max_b / 2))
		return (3);
	else
		return (4);
}
