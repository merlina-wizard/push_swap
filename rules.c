/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:48:19 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/10 22:11:04 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	sa(t_stack *a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*last;

	if (!(a->heada) || !a->heada->next)
		return ;
	first = a->heada;
	second = first->next;
	third = second->next;
	last = first->prev;
	if (third == first)
		two(first, second, a);
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

void	two(t_list *first, t_list *second, t_stack *a)
{
	second->next = first;
	a->heada = second;
	second->prev = first;
	first->prev = second;
	first->next = second;
}

void	sb(t_stack *a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*last;

	if (!(a->headb) || !a->headb->next)
		return ;
	first = a->headb;
	second = first->next;
	third = second->next;
	last = first->prev;
	if (third == first)
		two(first, second, a);
	else
	{
		a->headb = second;
		last->next = second;
		second->prev = last;
		second->next = first;
		first->prev = second;
		first->next = third;
		third->prev = first;
	}
}

void	ss(t_stack *a)
{
	sa(a);
	sb(a);
}

void	pb(t_stack *a)
{
	t_list	*first;
	t_list	*last;

	if (!a->heada)
		return ;
	first = a->heada;
	last = first->prev;
	if (first == last)
		a->heada = NULL;
	else
	{
		a->heada = first->next;
		last->next = first->next;
		first->next->prev = last;
	}
	if (!a->headb)
	{
		a->headb = first;
		first->next = first;
		first->prev = first;
	}
	else
		pa_pb_two(first, a);
}

void	pa(t_stack *a)
{
	t_list	*first;
	t_list	*last;

	if (!a->headb)
		return ;
	first = a->headb;
	last = first->prev;
	if (first == last)
		a->headb = NULL;
	else
	{
		a->headb = first->next;
		last->next = first->next;
		first->next->prev = last;
	}
	if (!a->heada)
	{
		a->heada = first;
		first->next = first;
		first->prev = first;
	}
	else
		pa_pb_two(first, a);
}
void	pa_pb_two(t_list *first, t_stack *a)
{
	first->next = a->heada;
	first->prev = a->heada->prev;
	a->heada->prev->next = first;
	a->heada->prev = first;
	a->heada = first;
}

void	ra(t_stack *a)
{
	t_list	*first;
	t_list	*last;
	t_list	*x;
	t_list	*y;

	if (!a || !a->heada->next)
		return ;
	first = a->heada;
	last = a->heada->prev;
	x = first->next;
	y = last->prev;
	last->prev = y;
	last->next = first;
	first->prev = last;
	first->next = x;
	a->heada = last;
}

void	rb(t_stack *a)
{
	t_list	*first;
	t_list	*last;
	t_list	*x;
	t_list	*y;

	if (!a || !a->headb->next)
		return ;
	first = a->headb;
	last = a->headb->prev;
	x = first->next;
	y = last->prev;
	last->prev = y;
	last->next = first;
	first->prev = last;
	first->next = x;
	a->headb = last;
}

void	rr(t_stack *a)
{
	ra(a);
	rb(a);
}
