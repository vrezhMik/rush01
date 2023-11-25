#include <stdio.h>
#define MAX_SIZE 6

void backtrack(char arr[], char path[], int len, int pos, char used[], char result[][4], int* resultCount) {
    if (pos == len) {
        for (int i = 0; i < len; i++) {
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

void generateOutcomes(char arr[], int len) {
    char result[24][4]; 
    int resultCount = 0;
    char used[4] = {0}; 

    char path[4];

    backtrack(arr, path, len, 0, used, result, &resultCount);

    for (int i = 0; i < resultCount; i++) {
        for (int j = 0; j < len; j++) {
            printf("%c ", result[i][j]);
        }
        printf("\n");
    }
}




int solve(char matrix[MAX_SIZE], int row, int col)
{
    int count = 1;
    int i = 1;
    int right = matrix[MAX_SIZE-1];
    int left = matrix[0];
    while( i < MAX_SIZE - 1)
    {
        
    }
    return 1;
}

int main(void)
{
    char matrix[MAX_SIZE][MAX_SIZE] = {
        {'0','4','3','2','1','0'},
        {'4','0','0','0','0','1'},
        {'3','0','0','0','0','2'},
        {'2','0','0','0','0','2'},
        {'1','0','0','0','0','2'},
        {'0','1','2','2','2','0'}
        };

char inputArray[4] = {'1', '2', '3', '4'};
    generateOutcomes(inputArray, 4);

}