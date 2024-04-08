/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:49:22 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/08 15:52:11 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	buble(char **mat, char **argv)
{
	int	i;
	int	j;

	while (mat)
	{
		j = 0;
		i = 0;
		if (mat[i] == argv[j])
		{
			i = 0;
			while (mat[++i] != argv[j])
			{
				if (mat[i] == argv[j])
					return (0);
			}
			j++;
		}
		i++;
	}
}
int	isnum(char *save)
{
	int	i;

	i = 0;
	while (save[i] == 32)
		i++;
	if (save[i] == '+' || save[i] == '-')
		i++;
	while (save[i] >= '0' && save[i] <= '9')
		i++;
	if (save[i] == '\0')
		return (1);
	return (0);


}

int	validation(char **mat, char **argv)
{
	int	i;

	i = 0;
	while (mat)
	{
		isnum(mat[i]);
		buble(**mat, argv);
		i++;
	}
}

int	god(int argc, char **argv, t_stack s)
{
	int		i;
	t_list	temp;

	i = 1;
	temp = NULL;
	if (argc > 2)
	{
		while (i < argc)
		{
			temp = lstnew(ft_atoi(argv[i]), temp);
		}
	}
}
