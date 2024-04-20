/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:31:29 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/20 19:15:51 by mamerlin         ###   ########.fr       */
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
		mini_sort(a);
	while (ft_lstsize(*a) > 3)
	{
		if (ft_lstsize(*b) <= 0)
		{
			ft_pb(a, b);
			ft_pb(a, b);
		}
		targeta = target_a(*a, *b);
		targetb = find_target(*b, targeta->nbr);
		ft_move(*a, targeta, *b, targetb);
	}
	//while ()
	//	ft_pa(a, b);
	if (check_if_sorted(*a))
		return ;
}

t_stack	*target_a(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*ret_a;
	t_stack	*head_a;
	int		tmp_cost;

	head_a = a;
	tmp_cost = INT_MAX;
	while (ft_lstlast(a)->nbr != a->nbr)
	{
		target = find_target(b, a->nbr);;
		if (find_cost(head_a, a, b, target) < tmp_cost)
		{
			tmp_cost = find_cost(head_a, a, b, target);
			a->cases = find_cost(head_a, a, b, target);
			ret_a = a;
		}
		a = a->next;
	}
	printf("cost finale = %i\n", tmp_cost);
	return (ret_a);
}

int	find_cost(t_stack *a, t_stack *target_a, t_stack *b, t_stack *target_b)
{
	ft_index(a);
	ft_index(b);
	return (ft_fakemove(a, target_a, b, target_b));
}

int	ft_fakemove(t_stack *a, t_stack *target_a, t_stack *b, t_stack *target_b)
{
	int	i;

	i = 0;
	printf("cases = %i\n", ft_case(target_a, target_b, ft_lstlast(a)->index,
			ft_lstlast(b)->index) == 1);
	if (ft_case(target_a, target_b, ft_lstlast(a)->index,
			ft_lstlast(b)->index) == 1)
	{
		print_stack(a);
		while (target_a->index != 1 && target_b->index != 1)
		{
			i += fake_rrr(a, b);
		}
		if (target_a->index == 1)
		{
			while (target_b->index != 1)
				i += fake_rrb(b);
		}
		else
		{
			while (target_a->index != 1)
				i += fake_rra(a);
		}
		printf("i = %i", i);
	}
	if (ft_case(target_a, target_b, ft_lstlast(a)->index,
			ft_lstlast(b)->index) == 2)
	{
		while (target_a->index != 1 && target_b->index != 1)
			i += fake_rr(a, b);
		if (target_a->index == 1)
		{
			while (target_b->index != 1)
				i += fake_rb(b);
		}
		else
		{
			while (target_a->index != 1)
				i += fake_ra(a);
		}
	}
	if (ft_case(target_a, target_b, ft_lstlast(a)->index,
			ft_lstlast(b)->index) == 3)
		i = ft_fakemove2(a, target_a, b, target_b, 3);
	else
		i = ft_fakemove2(a, target_a, b, target_b, 4);
	return (i);
}

int	ft_fakemove2(t_stack *a, t_stack *target_a, t_stack *b, t_stack *target_b, int i)
{
	if (i == 3)
	{
		i = 0;
		while (target_a->index != 1 && target_b->index != 1)
		{
			i += fake_rrb(b);
			i += fake_ra(a);
		}
		if (target_a->index == 1)
		{
			while (target_b->index != 1)
				i += fake_rrb(b);
		}
		else
		{
			while (target_a->index != 1)
				i += fake_ra(a);
		}
	}
	else
	{
		i = 0;
		while (target_a->index != 1 && target_b->index != 1)
		{
			i += fake_rra(b);
			i += fake_rb(a);
		}
		if (target_a->index == 1)
		{
			while (target_b->index != 1)
				i += fake_rra(b);
		}
		else
		{
			while (target_b->index != 1)
				i += fake_rb(a);
		}
	}
	return (i);
}

int	ft_case(t_stack *target_a, t_stack *target_b, long max_a, long max_b)
{
	if (target_a->index >= (max_a / 2) && target_b->index >= (max_b / 2))
		return (1);
	if (target_a->index <= (max_a / 2) && target_b->index <= (max_b / 2))
		return (2);
	if (target_a->index <= (max_a / 2) && target_b->index >= (max_b / 2))
		return (3);
	else
		return (4);
}
