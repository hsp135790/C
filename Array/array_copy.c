#include<stdio.h>

int main()
{
	char array1[6] = { 'A','B','C' };
	int i;

	for (i = 0;i < 6;i++)
		printf("%c ", array1[i]);
	printf("\n");

	array1[3] = array1[2];
	array1[4] = array1[1];
	array1[5] = array1[0];

	for (i = 0;i < 6;i++)
		printf("%c ", array1[i]);
}