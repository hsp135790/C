#include<stdio.h>

int main()
{
	int array[] = { 10,30,40,30,20 };
	int* p = NULL;
	int i,sum=0;

	p = array;

	for (i = 0;i < 5;i++)
	{
		sum = sum + *(p + i);
	}
	printf("%d\n", sum);

}