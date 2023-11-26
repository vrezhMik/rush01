/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_row_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrmikaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:12:45 by vrmikaye          #+#    #+#             */
/*   Updated: 2023/11/26 18:33:10 by vrmikaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check_row_left(char arr[], char left)
{
	int	count;
	int	i;
	int	max;

	count = 1;
	i = 0;
	max = arr[i];
	while (i < MAX_SIZE - 2)
	{
		if (max < arr[i + 1])
		{
			max = arr[i + 1];
			count++;
		}
		i++;
	}
	return (count == left - 48);
}
