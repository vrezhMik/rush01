#include "main.h"
int check_row_right(char arr[], char right)
{
    int count;
    int i;
    int max;

    count = 1;
    i = MAX_SIZE - 3;
    max = arr[i];
    while (i > -1)
    {
        if(max < arr[i-1])
        {
            max = arr[i-1];
            count++;
        }
        i--;
    }
    return count == right-48;
}
