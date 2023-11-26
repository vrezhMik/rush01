/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrmikaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:14:59 by vrmikaye          #+#    #+#             */
/*   Updated: 2023/11/26 18:32:59 by vrmikaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*check(char **result, char left, char right, char *top_indexes)
{
	int		i;
	int		j;
	char	*cols;

	j = 0;
	i = 0;
	cols = (char *) malloc(6);
	while (i < 24)
	{
		if (check_row_right(result[i], right))
		{	
			if (check_row_left(result[i], left))
			{
				cols[j] = *result[i];
				j++;
			}
		}
		i++;
	}
	(void) top_indexes;
	return (cols);
}
