/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrmikaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:27:21 by vrmikaye          #+#    #+#             */
/*   Updated: 2023/11/26 18:32:21 by vrmikaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	solve(char matrix[MAX_SIZE][MAX_SIZE], char *top_indexes)
{

    char	**result;
    int		i;
	char	inputArray[4] = {'1', '2', '3', '4'};

	result = generate_outcomes(inputArray, 4);
	i = 0;
	char **col_results = (char **)malloc(sizeof(char *)*4);
   	while (i < MAX_SIZE)
    {
        if (i > 0 && i < MAX_SIZE -1)
        {
            printf("%c and %c\n\n",matrix[i][0],matrix[i][MAX_SIZE-1]);
            (*col_results) = check(result, matrix[i][0], matrix[i][MAX_SIZE-1] , top_indexes);
            (*col_results)++;
        }
		i++;
    }

   
    return 1;
}

