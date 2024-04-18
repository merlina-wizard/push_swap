/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:52:35 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/18 17:03:06 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	fake_rra(t_stack *a)
{
	while (a)
	{
		if (a->index == (long)ft_lstsize(a))
			a->index = 1;
		else
			a->index = a->index + 1;
		a = a->next;
	}
}

void	fake_rrb(t_stack *b)
{
	while (b)
	{
		if (b->index == (long)ft_lstsize(b))
			b->index = 1;
		else
			b->index = b->index + 1;
		b = b->next;
	}
}

void	fake_rb(t_stack *b)
{
	while (b)
	{
		if (b->index == 1)
			b->index = (long)ft_lstsize(b);
		else
			b->index = b->index - 1;
		b = b->next;
	}
}

void	fake_ra(t_stack *a)
{
	while (a)
	{
		if (a->index == 1)
			a->index = (long)ft_lstsize(a);
		else
			a->index = a->index - 1;
		a = a->next;
	}
}

void	fake_rrr(t_stack *a, t_stack *b)
{
	fake_rra(a);
	fake_rrb(b);
}

void	ft_index(t_stack *stack)
{
	long	i;

	i = 1;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

void	fake_rr(t_stack *a, t_stack *b)
{
	fake_ra(a);
	fake_rb(b);
}
