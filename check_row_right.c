/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrmikaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:10:20 by vrmikaye          #+#    #+#             */
/*   Updated: 2023/11/26 18:33:20 by vrmikaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_row_right(char arr[], char right)
{
	int	count;
	int	i;
	int	max;

	count = 1;
	i = MAX_SIZE - 3;
	max = arr[i];
	while (i > -1)
	{
		if (max < arr[i - 1])
		{
			max = arr[i - 1];
			count++;
		}
		i--;
	}
	return (count == right - 48);
}
