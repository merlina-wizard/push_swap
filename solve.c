/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:31:29 by mamerlin          #+#    #+#             */
/*   Updated: 2024/05/02 17:39:22 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	solve(t_stack **a, t_stack **b)
{
	t_stack	*targeta;
	t_stack	*targetb;

	if (check_if_sorted(*a))
		return ;
	if (ft_lstsize(*a) <= 5)
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
		targeta = target_a(*a, *b, ft_lstsize(*a), ft_lstsize(*b));
		targetb = find_target(*b, targeta->nbr);
		ft_cases(a, targeta, b, targetb);
		ft_pb(a, b);
	}
	while (*b)
		ft_pa(a, b);
	if (check_if_sorted(*a))
		return ;
}

t_stack	*target_a(t_stack *a, t_stack *b, int size_a, int size_b)
{
	t_stack	*target;
	t_stack	*ret_a;
	int		tmp_cost;
	int		cost;

	tmp_cost = INT_MAX;
	while (a)
	{
		target = find_target(b, a->nbr);
		cost = find_cost(size_a, a->index, target->index, size_b);
		if (cost < tmp_cost)
		{
			ret_a = a;
			ret_a->cases = ft_case(size_a, a->index, target->index, size_b);
			tmp_cost = cost;
		}
		a = a->next;
	}
	return (ret_a);
}

void	ft_index(t_stack *stack)
{
	long	i;
	t_stack	*stack_head;

	i = 1;
	stack_head = stack;
	while (stack)
	{
		(stack)->index = i;
		stack = (stack)->next;
		i++;
	}
	stack = stack_head;
}

int	find_cost(int max_a, int index_a, int index_b, int max_b)
{
	int	i;
	int	cas;

	cas = ft_case(max_a, index_a, index_b, max_b);
	if (cas == 1)
	{
		if ((max_a - index_a) >= (max_b - index_b))
			i = (max_a - index_a) + 1;
		else
			i = (max_b - index_b) + 1;
	}
	else if (cas == 2)
	{
		if (index_a > index_b)
			i = index_a - 1;
		else
			i = index_b - 1;
	}
	else if (cas == 3)
		i = (index_a) + (max_b - index_b);
	else
		i = (index_b) + (max_a - index_a);
	return (i);
}

int	ft_case(int max_a, int index_a, int index_b, int max_b)
{
	if (index_a > ((max_a + 1) / 2) && index_b > ((max_b + 1) / 2))
		return (1);
	else if (index_a <= ((max_a + 1) / 2) && index_b <= ((max_b + 1) / 2))
		return (2);
	else if (index_a < ((max_a + 1) / 2) && index_b > ((max_b + 1) / 2))
		return (3);
	else
		return (4);
}
