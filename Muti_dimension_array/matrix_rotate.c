#include<stdio.h>

int main()
{
	int array1[2][4] = { {1,2,3,4},{5,6,7,8} };
	int array2[4][2] = { {5,1},{6,2},{7,3},{8,4} };
	int i, j;

	for (i = 0;i < 2;i++)
	{
		for (j = 0;j < 4;j++)
		{
			printf("%d ", array1[i][j]);
		}
		printf("\n");
	}
	printf("------------------\n");

	for (i = 0;i < 4;i++)
	{
		for (j = 0;j < 2;j++)
		{
			printf("%d ", array2[i][j]);
		}
		printf("\n");
	}
}