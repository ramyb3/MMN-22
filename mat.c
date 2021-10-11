#include "mat.h"

void add_mat(mat x, mat y, mat z) /* add_mat subroutine */
{
	int i,j;
	
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	z[i][j]= x[i][j]+y[i][j];	
}

void sub_mat(mat x, mat y, mat z) /* sub_mat subroutine */
{
	int i,j;
	
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	z[i][j]= (x[i][j])-(y[i][j]);
}

void mul_mat(mat x, mat y, mat z) /* mul_mat subroutine */
{
	int i,j;
	
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	z[i][j]= (x[i][j])*(y[i][j]);
}

void mul_scalar(mat x, float y, mat z) /* mul_scalar subroutine */
{
	int i,j;

	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	z[i][j]= (x[i][j])*y;
}

void trans_mat(mat x, mat y) /* trans_mat subroutine */
{
	int i,j;
	float temp;

	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	{
	temp= x[i][j];
	x[i][j]= y[i][j];
	y[i][j]= temp;
	}
}

void print_mat(mat x) /* print_mat subroutine */
{		
	int i,j;
	
	printf("\n");
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<3;j++)	
		printf("%.2f\t",x[i][j]); /* print numbers until 3 column */
	
		printf("%.2f\n",x[i][3]); /* print last column */
	}
}
		
void stop() /* stop subroutine */
{
	exit(0);
}
	
int read_mat(mat x, int count) /* read_mat subroutine */
{	
	mat y={0}; /* declaring new mat as variable to this function */
	int i, j, temp1, temp2, loop=0; /* variables to this function */
	char *text; /* gets the pointer of string from main in read_mat */	

	text = strtok(NULL,","); /* gets the number after inputed mat in command */
		
	for(i=0;(text != NULL);i++) /* while the command didn't end */
		for(j=0;(j<4)&&(text != NULL);j++) /* while the command didn't end + column<4 */
		{	
			/* check if the input number is legal */				
			if(atof(text)==0)
			if(strchr(text,'0')==NULL)				
			return 1; /* if the function doesn't works, it will return 1 */
				
			if(i<4) /* while row<4 */
			{
				temp1=i; /* row */
				temp2=j; /* column */
			
				y[i][j]=atof(text); /* insert in y mat the number from input */
				
				temp2++;/* next column */
			}
			
			loop++; /* count how many numbers in read_mat command */
			
			text = strtok(NULL,",");
		}
		
	if(count>=loop) /* if there is more ',' than numbers, there is an error */
	return 1; /* if the function doesn't works, it will return 1 */
	
	/* using the variable y mat */
		
	for(i=0;i<4;i++)
	for(j=0;j<4;j++)
	x[i][j]=y[i][j];
	
	/* in this loop, i fill 0 in all the empty cells */
			
	for(;temp1<4;temp1++)
	{
		for(;temp2<4;temp2++)		
		x[temp1][temp2]=0;

		
		if(temp2==4)
		temp2=0;	
	}	
	
	return 0; /* if the function works, it will return 0 */	
}
