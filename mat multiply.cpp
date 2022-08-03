#include<stdio.h>
int read_matrix(int a[25][25], int *row, int *col)
{
	int i,j;
	for(i=0;i<*row;i++)
	{
		for(j=0;j<*col;j++)
		scanf("%d",(*(a+i)+j));
	}
}
int print_mul_matrix(int a[25][25], int b[25][25],int *row1,int *col1row2,int *col2)
{
	int i,j,k,res;
	for(i=0;i<*row1;i++)
	{
		for(j=0;j<*col2;j++)
		{
			res=0;
			for(k=0;k<*col1row2;k++)
			{
				res+=((*(*(a+i)+k)) * (*(*(b+k)+j)));
			}
			printf("%d  ",res);
		}
		printf("\n");
	}
}

int main(){
	int mat1[25][25], mat2[25][25], m,n,p;
	printf("Enter the number of row in mat1:\t");
	scanf("%d",&m);
	printf("Enter the number of col in mat1 & row in mat2(as they must be same):\t");
	scanf("%d",&n);
	printf("Enter the number of col in mat2:\t");
	scanf("%d",&p);
	printf("Enter the elements in mat1:\n");
	read_matrix(mat1, &m, &n);
	printf("Enter the elements in mat2:\n");
	read_matrix(mat2, &n, &p);
	printf("The multiplied matrix is:\n");
	print_mul_matrix(mat1,mat2,&m,&n,&p);
	return 0;
	}
