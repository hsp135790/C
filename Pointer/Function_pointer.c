#include<stdio.h>
void arrInput(int* arr, int num);

int main()
{
	int array[5] = { 10,20,30,40,50 };

	int (*pfunc)(int*, int);

	pfunc = arrInput;
	pfunc(array, 5);



}

void arrInput(int* arr, int num)
{
	int i;

	for (i = 0;i < num;i++)
	{
		printf("%d ", *(arr + i));
	}
}