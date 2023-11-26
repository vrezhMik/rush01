#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"

char	**ft_calloc(void);
int		ft_strlen(char *str);
int		validation(int argc, char **argv);
void	init(char **map, char **argv);
int	g_size;

int	main(int argc, char *argv[])
{
	int		i;
	char	**map;

	if (validation(argc, argv) || ((map = ft_calloc()) == 0))
		return (-1);
	i = -1;
	init(map, argv);
	while (++i < g_size)
	{
		write(1, map[i], g_size);
		write(1, "\n", 1);
	}
	while (++i < g_size)
		free(map[i]);
	free(map);
	return (0);
}

char	**ft_calloc(void)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)malloc(g_size * sizeof(char *));
	i = -1;
	while (++i < g_size)
	{
		map[i] = (char *)malloc(g_size);
		if (map == 0 || map[i] == 0)
		{
			write(2, "No memory!\n", 11);
			return (0);
		}
	}
	i = -1;
	while (++i < g_size)
	{
		j = -1;
		while (++j < g_size)
			map[i][j] = '0';
	}
	return (map);
}

void	init(char **map, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (++j < g_size - 1)
		{
			if (*argv[1] == ' ')
				argv[1]++;
			map[i][j] = *argv[1];
			argv[1]++;
		}
		i += g_size - 1;
	}
	j = 0;
	while (*argv[1])
	{
		i = 0;
		while (++i < g_size - 1)
		{
			if (*argv[1] == ' ')
				argv[1]++;
			map[i][j] = *argv[1];
			argv[1]++;
		}
		j += g_size - 1;
	}
}

int	validation(int argc, char **argv)
{
	int	i;
	int	len;

	len = ft_strlen(argv[1]);
	if (argc > 2 || (len != 31 && len != 71))
		return (-1);
	i = 0;
	if (len == 31)
	{
		while (argv[1][i] >= '1' && argv[1][i] <= '4'
			&& (argv[1][i + 1] == ' ' || argv[1][i + 1] == '\0'))
			i += 2;
		g_size = 6;
	}
	else if (len == 71)
	{
		while (argv[1][i] >= '1' && argv[1][i] <= '9'
			&& (argv[1][i + 1] == ' ' || argv[1][i + 1] == '\0'))
			i += 2;
		g_size = 11;
	}
	if (i == len + 1)
		return (0);
	write(2, "Incorrect argument\n", 19);
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
