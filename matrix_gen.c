#include <unistd.h>

void	print_arr(char *arr[]);
int		matrix_gen(char **matr);

/*int	check_col_up(char **arr, char* top_indexes)
{
	char count;
    int i;
    int max;

    count = '1';
    i = 1;
	res = 0;
    max = arr[i][0];
    while(i < MAX_SIZE - 2)
    {
        if(max < arr[i+1][0])
        {
            max = arr[i+1][0];
            count++;
        }
        i++;
    }
	return (count == top_indexes[1]);
	
}
int	check_col_down(char **arr, char* top_indexes)
{
	char count;
    int i;
    int max;

	count = '1';
	i = 3;
    max = arr[i][0];
    while(i > -1)
    {
        if(max < arr[i-1][0])
        {
            max = arr[i-1][0];
            count++;
        }
        i--;
    }
	return (count == top_indexes[1]);
}*/

int	main(void)
{
	char 	**matr = {
		{"1234", NULL},
		{"2345", "3124", NULL},
		{"1023", "8213", NULL},
		{"2345", NULL}
	};

	matrix_gen(matr[0]);
	return (0);
}

int	matrix_gen(char **matr)
{
	int	i;
	int	j;
	int k;
	int l;
	char	*array[4];

	i = 0;
	while (matr[0][i])
	{
		j = 0;
		while (matr[1][j])
		{
			k = 0;
			while (matr[2][k])
			{
				l = 0;
				while (matr[3][l])
				{
					array[0] = matr[0][i];
					array[1] = matr[1][j];
					array[2] = matr[2][k];
					array[3] = matr[3][l];
					l++;
				}
				print_arr(array);
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}
void	print_arr(char *arr[])
{
	int	i;
	i = 0;
	while (i < 4)
	{
		write(1,*(arr+i), 4);
		write(1,"\n", 1);
		i++;
	}	
	write(1,"\n", 1);
}
