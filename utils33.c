/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils33.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:45:10 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/08 22:38:33 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (lst->next == 0)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		ft_lstlast(*lst)->prev = ft_lstlast(*lst)->next;
		ft_lstlast(*lst)->next = new;
	}
}

t_list	*ft_lstnew(int data)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->data = data;
	list->next = 0;
	list->prev = 0;
	return (list);
}
