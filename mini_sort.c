/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:09:09 by mamerlin          #+#    #+#             */
/*   Updated: 2024/05/03 19:58:05 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	mini_sort(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 3)
		sort_three(a);
	else if (ft_lstsize(*a) == 2)
		ft_sa(a);
	else if (ft_lstsize(*a) == 5)
		solve_five(a, b);
	if (check_if_sorted(*a))
		return ;
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

int	find_lowest(t_stack *a)
{
	t_stack	*tmp;
	int		num;

	tmp = (a);
	num = tmp->nbr;
	while (tmp)
	{
		if (num > tmp->nbr)
			num = tmp->nbr;
		tmp = tmp->next;
	}
	return (num);
}

int	find_second_lowest(t_stack *stack, int lowest)
{
	t_stack	*tmp;
	int		ret;

	tmp = stack;
	if (tmp->nbr != lowest)
		ret = tmp->nbr;
	else
		ret = tmp->next->nbr;
	while (tmp)
	{
		if (ret > tmp->nbr && tmp->nbr != lowest)
			ret = tmp->nbr;
		tmp = tmp->next;
	}
	return (ret);
}

void	solve_five(t_stack **a, t_stack **b)
{
	int	i;
	int	lowest;
	int	second_lowest;
	int	size;

	i = 0;
	size = ft_lstsize(*a);
	lowest = find_lowest(*a);
	second_lowest = find_second_lowest(*a, lowest);
	while (i < size)
	{
		if ((*a)->nbr == lowest || (*a)->nbr == second_lowest)
			ft_pb(a, b);
		else
			ft_ra(a);
		i++;
	}
	if (!check_if_sorted(*a))
		sort_three(a);
	if (check_if_sorted(*b))
		ft_sb(b);
	ft_pa(a, b);
	ft_pa(a, b);
}
