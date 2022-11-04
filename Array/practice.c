#include<stdio.h>

int main()
{
	int array[3] = { 1,2,3 };
	int i;

	for (i = 0;i < 3;i++)
		printf("%x ", &array[i]);
	printf("\n");

	for (i = 0;i < 3;i++)
		printf("%d ", *&array[i]);
	printf("\n");

	for (i = 0;i < 3;i++)
		printf("%d ", array[i]);
	printf("\n");

	for (i = 0;i < 3;i++)
		printf("%d ", *(array+i));
	printf("\n");


	
}