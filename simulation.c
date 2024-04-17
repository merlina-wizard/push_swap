/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:52:35 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/17 11:50:45 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"


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
