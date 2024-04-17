/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:31:29 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/17 19:34:26 by mamerlin         ###   ########.fr       */
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
		target_a(&a, &b);
	}
	if (ft_lstsize(*a) <= 3)
		mini_sort(a);
}

void	mini_sort(t_stack **a)
{
	if (ft_lstsize(*a) == 3)
		sort_three(a);
	if (ft_lstsize(*a) == 2)
		ft_sa(*a);
}

t_stack	*target_a(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*ret;
	int		tmp_cost;

	tmp_cost = INT_MAX;
	while (a != ft_lstlast(a))
	{
		target = find_target(b, a->nbr);
		if (find_cost(b, target) < tmp_cost)
		{
			tmp_cost = find_cost(b, target);
			ret = a;
		}
	}
	return (ret);
}

int	find_cost(t_stack *b, t_stack *target)
{
	
}

void	sort_three(t_stack **a)
{
	long	max;

	if ((*a)->nbr > (*a)->next->nbr && (*a)->nbr > (*a)->next->next->nbr)
	{
		max = (*a)->nbr;
		ft_ra(a);
	}
	if ((*a)->next->nbr > (*a)->nbr && (*a)->next->nbr > (*a)->next->next->nbr)
	{
		max = (*a)->next->nbr;
		ft_rra(a);
	}
	else
		max = (*a)->next->next->nbr;
	if (ft_lstlast(*a)->nbr == max)
	{
		if (!check_if_sorted(*a))
			ft_sa(a);
		return ;
	}
	return ;
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

t_stack	*find_target(t_stack *stacks, int target)
{
	t_stack	*ret;

	ret = small_target(stacks, target);
	if (ret == NULL)
		ret = big_target(stacks, target);
	return (ret);
}

t_stack	*small_target(t_stack *stacks, int target)
{
	t_stack	*ret;
	int		compare;
	t_stack	*iter;

	compare = INT_MIN;
	ret = NULL;
	iter = stacks;
	while (iter)
	{
		if (iter->nbr > compare && iter->nbr < target)
		{
			compare = iter->nbr;
			ret = iter;
		}
		iter = iter->next;
	}
	return (ret);
}

static	t_stack	*big_target(t_stack *stacks, int target)
{
	t_stack	*ret;
	int		compare;
	t_stack	*iter;

	compare = INT_MAX;
	ret = NULL;
	iter = stacks;
	while (iter)
	{
		if (iter->nbr < compare && iter->nbr > target)
		{
			compare = iter->nbr;
			ret = iter;
		}
		iter = iter->next;
	}
	return (ret);
}
