/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:09:09 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/18 17:11:37 by mamerlin         ###   ########.fr       */
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

void	mini_sort(t_stack **a)
{
	if (ft_lstsize(*a) == 3)
		sort_three(a);
	if (ft_lstsize(*a) == 2)
		ft_sa(a);
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
