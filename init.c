/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:43:21 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/09 16:33:59 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	stack_init(t_list **a, char **mat)
{
	int		i;

	i = 0;
	while (mat[i] != NULL)
	{
		if (!create(a, mat[i]))
			return (0);
		i++;
	}
	(*a)->prev = ft_lstlast(*a);
	ft_lstlast(*a)->next = *a;
	return (1);
}

int	create(t_list **list, char	*mat)
{
	long long	nbr;

	nbr = ft_atoi(mat);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	if (!list)
		ft_lstnew(nbr);
	ft_lstadd_back(list, ft_lstnew(nbr));
	return (1);
}
