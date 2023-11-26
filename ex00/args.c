#include <stdlib.h>

int		count_validate_args(char **argv)
{
	int i;
	int n;

	i = -1;
	n = 0;
	while (argv[1][++i])
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			return (-1);
		n++;
		if (argv[1][i + 1] == '\0')
			return (n);
		else if (argv[1][i + 1] != ' ')
			return (-1);
		i++;
	}
	return (n);
}

int		**get_validate_args(char **argv, int size)
{
	int		i;
	int		j;
	int		**tab;

	tab = malloc(sizeof(int*) * (size / 4));
	i = -1;
	j = 0;
	while (argv[1][++i])
	{
		if (j % (size / 4) == 0)
			tab[j / (size / 4)] = malloc(sizeof(int) * (size / 4));
		tab[j / (size / 4)][j % (size / 4)] = argv[1][i] - '0';
		if (argv[1][i + 1] != '\0')
			i++;
		j++;
	}
	return (tab);
}

int		**validate_args(int argc, char **argv, int *size)
{
	int		number_of_args;
	int		**validate_args;

	if (argc == 2)
	{
		number_of_args = count_validate_args(argv);
		if (number_of_args == -1 || number_of_args % 4 != 0 || number_of_args < 12)
		{
			return (NULL);
		}
		else
		{
			*size = number_of_args / 4;
			validate_args = get_validate_args(argv, number_of_args);
			return (validate_args);
		}
	}
	return (NULL);
}
