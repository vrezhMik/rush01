#ifndef MAIN_H
#define MAIN_H
#define MAX_SIZE 6
#include <stdlib.h>
#include <stdio.h>
void backtrack(char arr[], char path[], int len, int pos, char used[], char **result, int* resultCount);
char **generate_outcomes(char arr[], int len);
int check_row_right(char arr[], char right);
int solve(char matrix[MAX_SIZE][MAX_SIZE], char *top_indexes);
int check_row_left(char arr[], char left);
char * check(char **result, char left, char right, char *top_indexes);


#endif
