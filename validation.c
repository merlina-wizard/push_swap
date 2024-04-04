/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:49:22 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/04 17:41:36 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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

int	validate(int argc, char **argv)
{
	char	**save;
	int		i;

	i = -1;
	if (argc == 2)
		{
			save = ft_split(argv[1], ' ');
			while (save[++i])
			{
				if (!isnum(save[i]))
					{
						free(save);
						return (0);
					}
			}
		}
	if (argc > 2)
	{
		while (++i < argc)
			{
				if (!isnum(argv[i]) && i >= 1)
						return (0);
			}
	}
		return (1);
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
