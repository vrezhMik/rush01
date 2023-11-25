/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:17:21 by dasargsy          #+#    #+#             */
/*   Updated: 2023/11/25 17:31:18 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	destroy_matrix(int size, char **matrix);

void	print_matrix(int size, char **matrix)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (i <= size - 2)
	{
		while (j <= size - 2)
		{
			write(1, &matrix[i][j], 1);
			if (j != size)
			{
				write(1, " ", 1);
			}
			j++;
		}
		j = 1;
		++i;
		write(1, "\n", 1);
	}
	destroy_matrix(size, matrix);
}
