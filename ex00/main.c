/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dasargsy <dasargsy@student.42yerevan.am>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 21:02:27 by dasargsy          #+#    #+#             */
/*   Updated: 2023/11/26 21:02:51 by dasargsy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		**validate_args(int argc, char **argv, int *number_of_args);
void	solve(int **locked, int size);
void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	int		**matrix;
	int		size;

	matrix = validate_args(argc, argv, &size);
	if (matrix != NULL)
	{
		solve(matrix, size);
	}
	else
		ft_putstr("Error\n");
}
