/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:57:54 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/18 16:59:04 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_rra(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*pre;

	pre = (*a);
	while (pre->next->next)
		pre = pre->next;
	tmp = (*a);
	(*a) = ft_lstlast(*a);
	(*a)->next = tmp;
	pre->next = NULL;
}

void	ft_rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*pre;

	pre = (*b);
	while (pre->next->next)
		pre = pre->next;
	tmp = (*b);
	(*b) = ft_lstlast(*b);
	(*b)->next = tmp;
	pre->next = NULL;
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(a);
	ft_rrb(b);
}
