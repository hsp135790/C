#include<stdio.h>

int main()
{
	int a[5] = { 90,78,77,98,98 };
	int b[5] = { 80,45,67,88,57 };
	int c[5] = { 88,99,65,55,74 };
	int line[3]={0,0,0};
	int column[5]={0,0,0,0,0};
	int total = 0;
	int i,j;

	//line
	for (j = 0;j < 5;j++)
	{
		line[0] = line[0] + a[j];
	}
	for (j = 0;j < 5;j++)
	{
		line[1] = line[1] + b[j];
	}
	for (j = 0;j < 5;j++)
	{
		line[2] = line[2] + c[j];
	}
	//column
	for (j = 0;j < 5;j++)
	{
		column[j] = a[j] + b[j] + c[j];
	}
	//total
	for (i = 0;i < 3;i++)
	{
		total = total + line[i];
	}


	for (i = 0;i < 3;i++)
		printf("%d line's sum : %d \n",i+1, line[i]);
	printf("\n");
	
	for (i = 0;i < 5;i++)
		printf("%d column's sum : %d\n", i + 1, column[i]);
	printf("\n");

	printf("Whole sum : %d\n", total);
	printf("Average : %.2lf\n", (double)total / 3);

	

	
	
}