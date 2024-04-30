/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:35:05 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/30 23:33:20 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_case2(t_stack **a, t_stack *target_a, t_stack **b, t_stack *target_b)
{
	while ((*a)->nbr != target_a->nbr && (*b)->nbr != target_b->nbr)
		ft_rr(a, b);
	if ((*a)->nbr == target_a->nbr)
	{
		while ((*b)->nbr != target_b->nbr)
			ft_rb(b);
	}
	else
	{
		while ((*a)->nbr != target_a->nbr)
			ft_ra(a);
	}
}

void	ft_case3(t_stack **a, t_stack *target_a, t_stack **b, t_stack *target_b)
{
	while ((*a)->nbr != target_a->nbr && (*b)->nbr != target_b->nbr)
	{
		ft_rrb(b);
		ft_ra(a);
	}
	if ((*a)->nbr == target_a->nbr)
	{
		while (target_b->nbr != (*b)->nbr)
			ft_rrb(b);
	}
	else
	{
		while (target_a->nbr != (*a)->nbr)
			ft_ra(a);
	}
}

void	ft_case4(t_stack **a, t_stack *target_a, t_stack **b, t_stack *target_b)
{
	while (((*a)->nbr != target_a->nbr) && ((*b)->nbr != target_b->nbr))
	{
		ft_rra(a);
		ft_rb(b);
	}
	if ((*a)->nbr == target_a->nbr)
	{
		while (target_b->nbr != (*b)->nbr)
			ft_rb(b);
	}
	else
	{
		while (target_a->nbr != (*a)->nbr)
			ft_rra(a);
	}
}

void	ft_cases(t_stack **a, t_stack *target_a, t_stack **b, t_stack *target_b)
{
	int	cas;

	cas = target_a->cases;
	if (cas == 1)
	{
		while ((*a)->nbr != target_a->nbr && (*b)->nbr != target_b->nbr)
			ft_rrr(a, b);
		if ((*a)->nbr == target_a->nbr)
		{
			while ((*b)->nbr != target_b->nbr)
				ft_rrb(b);
		}
		else
		{
			while ((*a)->nbr != target_a->nbr)
				ft_rra(a);
		}
	}
	else if (cas == 2)
		ft_case2(a, target_a, b, target_b);
	else if (cas == 3)
		ft_case3(a, target_a, b, target_b);
	else
		ft_case4(a, target_a, b, target_b);
}
