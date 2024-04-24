/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:05:00 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/24 22:59:31 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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

static	t_stack	*big_target(t_stack *stacks)
{
	t_stack	*ret;
	int		compare;
	t_stack	*iter;

	compare = INT_MIN;
	ret = NULL;
	iter = stacks;
	while (iter)
	{
		if (iter->nbr > compare)
		{
			compare = iter->nbr;
			ret = iter;
		}
		iter = iter->next;
	}
	return (ret);
}

t_stack	*find_target(t_stack *stacks, int target)
{
	t_stack	*ret;

	ret = small_target(stacks, target);
	if (ret == NULL)
		ret = big_target(stacks);
	return (ret);
}
