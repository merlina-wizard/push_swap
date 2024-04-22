/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:52:35 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/22 21:45:02 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	fake_rra(t_stack **a)
{
	int	i;

	i = (long)ft_lstsize((*a));
	while ((*a))
	{
		if ((*a)->index == i)
			(*a)->index = 1;
		else
			(*a)->index = (*a)->index + 1;
		(*a) = (*a)->next;
	}
	return (1);
}

int	fake_rrb(t_stack **b)
{
	int	i;

	i = (long)ft_lstsize(*b);
	while (*b)
	{
		if ((*b)->index == i)
			(*b)->index = 1;
		else
			(*b)->index = (*b)->index + 1;
		(*b) = (*b)->next;
	}
	return (1);
}

int	fake_rb(t_stack **b)
{
	int	i;

	i = (long)ft_lstsize(*b);
	while (*b)
	{
		if ((*b)->index == 1)
			(*b)->index = i;
		else
			(*b)->index = (*b)->index - 1;
		(*b) = (*b)->next;
	}
	return (1);
}

int	fake_ra(t_stack **a)
{
	long	i;

	i = (long)ft_lstsize(*a);
	while (*a)
	{
		if ((*a)->index == 1)
			(*a)->index = i;
		else
			(*a)->index = (*a)->index - 1;
		(*a) = (*a)->next;
	}
	return (1);
}

int	fake_rrr(t_stack **a, t_stack **b)
{
	fake_rra(a);
	fake_rrb(b);
	return (1);
}

void	ft_index(t_stack **stack)
{
	long	i;

	i = 1;
	while (*stack)
	{
		(*stack)->index = i;
		*stack = (*stack)->next;
		i++;
	}
}

int	fake_rr(t_stack **a, t_stack **b)
{
	fake_ra(a);
	fake_rb(b);
	return (1);
}
