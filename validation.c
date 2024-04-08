		//martina, sono te dal futuro. scappa
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:49:22 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/08 16:29:10 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	michael_buble(char **mat)
{
	int	i;
	int	j;

		i = 0;
	while (mat[i])
	{
		j = i + 1;
		while (mat[j])
		{
			if (ft_atoi(mat[i]) == ft_atoi(mat[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	isnum(char *save)
{
	int	i;

	i = 0;
	while (save[i] == 32)
		i++;
	if (save[i] == '+' || save[i] == '-')
		{
			if (save[i + 1] == '\0')
				return (0);
			i++;
		}
	while (save[i] >= '0' && save[i] <= '9')
		i++;
	if (save[i] == '\0')
		return (1);
	return (0);
}

int	validation(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		if (!isnum(mat[i]))
			return (printf("non ci sono solo numeri\n"));
		i++;
	}
		if (!michael_buble(mat))
			return (printf("ci sono duplicati\n"));
	return (0);
}

char	**mat(int argc, char **argv)
{
	char	**mat;
	int		i;

	i = 0;
	mat = (char **)malloc(sizeof(char *) * (argc));
	if (!mat)
		return (NULL);
	mat[argc - 1] = NULL;
	while (i < argc - 1)
	{
		mat[i] = ft_strdup(argv[i]);
		i++;
	}
	return (mat);
}
