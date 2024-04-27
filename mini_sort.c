/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:09:09 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/28 00:20:53 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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

void	mini_sort(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 3)
		sort_three(a);
	if (ft_lstsize(*a) == 2)
		ft_sa(a);
	if (ft_lstsize(*a) == 5)
		solve_five(a, b);
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

void	solve_five2(t_stack **a,t_stack **b)
{
	while (*b)
	{
		if ((*b)->index < (ft_lstsize(*b) / 2))
			ft_rb(b);
		else
			ft_rrb(b);
		ft_pa(a, b);
	}
}

void	solve_five(t_stack **a, t_stack **b)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (i < 3)
	{
		min = lowest_num(a);
		while ((*a)->nbr != min)
		{
			if ((*a)->index < (ft_lstsize(*a) / 2))
				ft_ra(a);
			else
				ft_rra(a);
		}
		ft_pb(a, b);
		i++;
	}
	mini_sort(a, b);
	solve_five2(a, b);
}
