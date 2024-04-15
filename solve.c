/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:31:29 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/13 17:03:06 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	find_corresponding_index(t_stack *head, t_stack *target)
{
	int		i;
	t_stack	*iter;

	i = 0;
	iter = head;
	while (iter != target)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}

t_stack	*find_target(t_stack *stack, int nbr)
{
	int	i;
	t_stack *tmp;

	tmp = stack;
	i = nbr - 1;
	if (!stack)
		return NULL;
	while(tmp->next)
	{
		if (tmp->nbr == i)
			return (tmp);
		tmp = tmp->next;
		i--;
	}
	i = nbr;
	tmp = stack;
	while(tmp->next)
	{
		if (tmp->nbr == i)
			return (tmp);
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}
