/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:09:26 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/08 17:30:23 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int main(int argc, char **argv)
{
	char	**matrix;

	matrix = NULL;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		{
			matrix = ft_split(argv[1], ' ');
			printf("culo\n");
		}
	if (argc > 2)
		{
			matrix = mat(argc, argv + 1);
			printf("culo1\n");
		}
	if (!validation(matrix))
	{
		ft_close_matrix(matrix);
		return (1);
	}
	return (1);
}
