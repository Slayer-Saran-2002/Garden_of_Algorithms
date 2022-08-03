#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int a=25;
	int*p=&a;
	int**f=&p;
	printf("%d %d %d",a,p,**f);

 return 0;
}



