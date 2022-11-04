#include<stdio.h>

int main()
{
	int table[9][9];
	int i, j;

	for (i = 0;i < 9;i++)
	{
		for (j = 0;j < 9;j++)
		{
			table[i][j] = (i+1) * (j+1);
		}
	}

	for (i = 0;i < 9;i++)
	{
		printf("-------%d´Ü-------\n", i+1);
		for (j = 0;j < 9;j++)
		{
			printf("%d x %d = %d\n", i+1, j+1, table[i][j]);
		}
		printf("\n");
		
	}
}