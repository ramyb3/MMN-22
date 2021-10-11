#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUM 200
#define LENGTH 5

typedef float mat[4][4];

void add_mat(mat, mat, mat);
void sub_mat(mat, mat, mat); 
void mul_mat(mat, mat, mat);
void mul_scalar(mat, float, mat);
void trans_mat(mat, mat); 
void print_mat(mat); 
void stop(void);
int read_mat(mat, int);
