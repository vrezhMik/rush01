#include <stdlib.h>

int		**validate_args(int argc, char **argv, int *number_of_args);
void	solve(int **locked, int size);
void	ft_putstr(char *str);

int		main(int argc, char **argv)
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
