/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:01:31 by dasargsy          #+#    #+#             */
/*   Updated: 2023/11/26 21:02:18 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	lock_hori(int ***table, int **matrix, int size, int i)
{
	int	j;

	if (matrix[0][i] == size)
	{
		j = -1;
		while (++j < size)
			table[1][j][i] = j + 1;
	}
	else if (matrix[0][i] == 1)
		table[1][0][i] = size;
	if (matrix[1][i] == size)
	{
		j = -1;
		while (++j < size)
			table[1][size - j - 1][i] = j + 1;
	}
	else if (matrix[1][i] == 1)
		table[1][size - 1][i] = size;
}

void	lock_vert(int ***table, int **matrix, int size, int i)
{
	int	j;

	if (matrix[2][i] == size)
	{
		j = -1;
		while (++j < size)
			table[1][i][j] = j + 1;
	}
	else if (matrix[2][i] == 1)
		table[1][i][0] = size;
	if (matrix[3][i] == size)
	{
		j = -1;
		while (++j < size)
			table[1][i][size - j - 1] = j + 1;
	}
	else if (matrix[3][i] == 1)
		table[1][i][size - 1] = size;
}

void	assemble(int ***table, int **matrix, int size, int i)
{
	int		j;

	j = -1;
	table[2][i] = malloc(sizeof(int) * size);
	while (++j < size)
	{
		table[2][i][j] = matrix[i][j];
	}
}

void	lock(int ***table, int **matrix, int size)
{
	int		i;

	table[2] = malloc (sizeof(int *) * 4);
	i = -1;
	while (++i < 4)
	{
		lock_hori(table, matrix, size, i);
		lock_vert(table, matrix, size, i);
		assemble(table, matrix, size, i);
	}
}
