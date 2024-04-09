/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:48:19 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/09 16:54:31 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sa(t_stack *a)  //heada
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*last;

	if (!(a->heada) || !a->heada->next)
		return;
	first = a->heada;
	second = first->next;
	third = second->next;
	last = first->prev;
	if (third == first)
	{
		second->next = first;
		a->heada = second;
		second->prev = first;
		first->prev = second;
		first->next = second;
	}
	else
	{
		a->heada = second;
		last->next = second;
		second->prev = last;
		second->next = first;
		first->prev = second;
		first->next = third;
		third->prev = first;
	}
}

int	sb(t_stack *a)
{
	t_list	*b;
	t_list	*c;

	b = a->headb->next;
	c = a->headb->prev;
	if (a)
	{
		b->prev = c;
		b->next = a->headb;
		a->headb->prev = b;
		a->headb->next = c;
		return (1);
	}
	return (0);
}
