/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_outcomes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrmikaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:22:00 by vrmikaye          #+#    #+#             */
/*   Updated: 2023/11/26 18:32:28 by vrmikaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	**generate_outcomes(char arr[], int len)
{
	char	**result;
	int		result_count;
	char	used[4] = {0};
	char	path[4];

	result_count = 0;
	result = (char **)malloc(24 * sizeof (char *));
	backtrack(arr, path, len, 0, used, result, &result_count);
	return (result);
}
