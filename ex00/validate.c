/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:03:23 by dasargsy          #+#    #+#             */
/*   Updated: 2023/11/26 21:03:46 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	print(int ***table, int size);

void	check_valid_up(int ***table, int size, int i, int *erreur)
{
	int		j;
	int		n;
	int		s;

	if (table[2][0][i] != 1 && table[2][0][i] != size)
	{
		j = -1;
		n = 0;
		s = 0;
		while (++j < size && *erreur == 0 && s != size)
		{
			if (table[0][j][i] > s)
			{
				n++;
				s = table[0][j][i];
			}
		}
		if (table[2][0][i] != n)
			*erreur = 1;
	}
}

void	check_valid_down(int ***table, int size, int i, int *erreur)
{
	int		j;
	int		n;
	int		s;

	if (table[2][1][i] != 1 && table[2][1][i] != size)
	{
		j = -1;
		n = 0;
		s = 0;
		while (++j < size && *erreur == 0 && s != size)
		{
			if (table[0][size - j - 1][i] > s)
			{
				n++;
				s = table[0][size - j - 1][i];
			}
		}
		if (table[2][1][i] != n)
			*erreur = 1;
	}
}

void	check_valid_left(int ***table, int size, int i, int *erreur)
{
	int		j;
	int		n;
	int		s;

	if (table[2][2][i] != 1 && table[2][2][i] != size)
	{
		j = -1;
		n = 0;
		s = 0;
		while (++j < size && *erreur == 0 && s != size)
		{
			if (table[0][i][j] > s)
			{
				n++;
				s = table[0][i][j];
			}
		}
		if (table[2][2][i] != n)
			*erreur = 1;
	}
}

void	check_valid_right(int ***table, int size, int i, int *erreur)
{
	int		j;
	int		n;
	int		s;

	if (table[2][3][i] != 1 && table[2][3][i] != size)
	{
		j = -1;
		n = 0;
		s = 0;
		while (++j < size && *erreur == 0 && s != size)
		{
			if (table[0][i][size - j - 1] > s)
			{
				n++;
				s = table[0][i][size - j - 1];
			}
		}
		if (table[2][3][i] != n)
			*erreur = 1;
	}
}

int	check_valid(int ***table, int size)
{
	int		i;
	int		erreur;

	i = -1;
	erreur = 0;
	while (++i < size && erreur == 0)
	{
		check_valid_up(table, size, i, &erreur);
		check_valid_down(table, size, i, &erreur);
		check_valid_left(table, size, i, &erreur);
		check_valid_right(table, size, i, &erreur);
	}
	if (erreur == 0)
	{
		print(table, size);
		free(table);
		return (1);
	}
	return (0);
}
