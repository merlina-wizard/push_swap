/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bho.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:45:07 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/08 15:20:37 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

char	**mat(int argc, char **argv);
{
	char	**mat;
	int		i;

	i = 0;
	mat = (char **)malloc((char *)sizeof * argc);
	if (!mat)
		retuirn (NULL);
	mat[argc] = NULL;
	while (mat != NULL)
	{
		mat[i] = argv[i];
		i++;
	}
	return (mat);
}
