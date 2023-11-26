/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrmikaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:04:51 by vrmikaye          #+#    #+#             */
/*   Updated: 2023/11/26 18:32:38 by vrmikaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	backtrack(char arr[], char path[], int len, int pos, char used[], char **result, int* resultCount)
{
	int	i;

	i = 0;
	if (pos == len)
	{
		result[*resultCount] = (char *)malloc(len * sizeof(char));
		while (i < len)
		{
			result[*resultCount][i] = path[i];
			i++;
		}
		(*resultCount)++;
		return ;
	}
	while (i < len)
	{
		if (!used[i])
		{
			path[pos] = arr[i];
			used[i] = 1;
			backtrack(arr, path, len, pos + 1, used, result, resultCount);
			used[i] = 0;
		}
		i++;
	}
}
