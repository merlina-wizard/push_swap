/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:31:29 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/17 10:25:23 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	solve(t_stack *a, t_stack *b)
{
	if (b == NULL)
	{
		pb(&a);
		pb(&a);
	}

	calculate_cost(&a, &b);
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	while (a != ft_lstlast(&a))
	{


	}
}
