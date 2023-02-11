#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
struct Matrix
{
	int *A;
	int n;
};
// we only store the non zero values
void set(struct Matrix *m,int i,int j,int x){
	if(i>=j)
	{
		m->A[i*(i-1)/2+(j-1)]=x;
	}
	
	 
}
int get(struct Matrix m,int i,int j){
	if(i==j)
	return m.A[i-1];
	else 
	return 0;	
}
void display(struct Matrix m){
	int i,j;
	for(i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++){
  		if(i>=j)
		printf("%d ",m.A[i*(i-1)/2+(j-1)]);
		else
		printf("0 ");	
		}
		printf("\n");
	}
}
	
int main()
{
	struct Matrix m;
	int i,j,x;
	printf("Enter the dimenstion of the matrix : ");
	scanf("%d",&m.n);
	m.A=(int *)malloc(m.n*(m.n+1)/2*sizeof(int));

	for (i=1;i<=m.n;i++){
		for(j=1;j<=m.n;j++)
		{
		printf("enter the value in position %d %d  ",i,j);
		scanf("%d",&x);
		set(&m,i,j,x);
		} 
	}
	display(m);
 return 0;
}



