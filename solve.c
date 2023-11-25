#include "main.h"
#include <stdio.h>


void backtrack(char arr[], char path[], int len, int pos, char used[], char **result, int* resultCount) {
    if (pos == len) {
         result[*resultCount] = (char *)malloc(len*sizeof(char));
        for (int i = 0; i < len ; i++) {
           
            result[*resultCount][i] = path[i];
        }
        (*resultCount)++;
        return;
    }

    for (int i = 0; i < len; i++) {
        if (!used[i]) {
            path[pos] = arr[i];
            used[i] = 1;

            backtrack(arr, path, len, pos + 1, used, result, resultCount);
            used[i] = 0;
        }
    }
}

char **generateOutcomes(char arr[], int len) {
    char **result; 
    int resultCount = 0;
    char used[4] = {0}; 

    char path[4];

    result = (char**)malloc(24 * sizeof(char *));
    backtrack(arr, path, len, 0, used, result, &resultCount);

    return result;
}



int check(char **result, char left, char right, char *top_indexes)
{   
    (void)top_indexes;
    for(int i = 0; i < 24; i++)
    {
        if(check_row_right(result[i], right) && check_row_left(result[i], left))
        {
            printf("%s \n",result[i]);
        }
    }

   
    return 1;
}

int solve(char matrix[MAX_SIZE][MAX_SIZE], char *top_indexes)
{

    char **result;
    char inputArray[4] = {'1', '2', '3', '4'};

    result = generateOutcomes(inputArray, 4);
    for(int i = 0; i < MAX_SIZE; i++)
    {
        if(i > 0 && i < MAX_SIZE -1)
        {
            printf("%c and %c\n\n",matrix[i][0],matrix[i][MAX_SIZE-1]);
                check(result, matrix[i][0], matrix[i][MAX_SIZE-1] , top_indexes);
        }
    }

   
    return 1;
}

int main(void)
{
    char matrix[MAX_SIZE][MAX_SIZE] = {
        {'0','4','3','2','1','0'},
        {'2','0','0','0','0','3'},
        {'3','0','0','0','0','1'},
        {'3','0','0','0','0','2'},
        {'1','0','0','0','0','3'},
        {'0','1','2','2','2','0'}
        };
    char *top_indexes = (char *)malloc(8);
    int z = 0;
    for(int i = 0; i < MAX_SIZE ; i += MAX_SIZE-1)
    {
        for(int j = 1; j < MAX_SIZE - 1; j++)
        {
            top_indexes[z] = matrix[i][j];
            z++;
        }
    }

    solve(matrix , top_indexes);

}