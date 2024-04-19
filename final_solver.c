/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_solver.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 13:35:05 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/19 20:45:14 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_move(t_stack *a, t_stack *target_a, t_stack *b, t_stack *target_b)
{
	ft_index(a);
	ft_index(b);
	if (ft_case(target_a, target_b, ft_lstlast(a)->index,
			ft_lstlast(b)->index == 1))
	{
		while (a->nbr != target_a->nbr || b->nbr != target_b->nbr)
			ft_rrr(a, b);
		if (a->nbr == target_a->nbr)
		{
			while (b->nbr != target_b->nbr)
				ft_rrb(b);
		}
		else
		{
			while (a->nbr != target_a->nbr)
				ft_rra(a);
		}
	}
	if (ft_case(target_a, target_b, ft_lstlast(a)->index,
			ft_lstlast(b)->index == 2))
	{
		while (a->nbr != target_a->nbr || b->nbr != target_b->nbr)
			ft_rr(a, b);
		if (a->nbr == target_a->nbr)
		{
			while (b->nbr != target_b->nbr)
				ft_rb(b);
		}
		else
		{
			while (a->nbr != target_a->nbr)
				ft_ra(a);
		}
	}
	if ((ft_case(target_a, target_b, ft_lstlast(a)->index,
			ft_lstlast(b)->index == 3)))
		ft_move2(a, target_a, b, target_b, 3);
	else
		ft_move2(a, target_a, b, target_b, 4);
	ft_pa(&a, &b);
}

void	ft_move2(t_stack *a, t_stack *target_a, t_stack *b, t_stack *target_b, int i)
{
	if (i == 3)
	{
		i = 0;
		while (a->nbr != target_a->nbr || b->nbr != target_b->nbr)
		{
			ft_rrb(b);
			ft_ra(a);
		}
		if (a->nbr == target_a->nbr)
		{
			while (target_b->nbr != b->nbr)
				ft_rrb(b);
		}
		else
		{
			while (target_a->nbr != a->nbr)
				ft_ra(a);
		}
	}
	else
	{
		i = 0;
		while (a->nbr != target_a->nbr || b->nbr != target_b->nbr)
		{
			ft_rra(b);
			ft_rb(a);
		}
		if (a->nbr == target_a->nbr)
		{
			while (target_a->nbr != a->nbr)
				i += fake_rra(b);
		}
		else
		{
			while (target_b->nbr != b->nbr)
				i += fake_rb(a);
		}
	}
}
