#include<stdio.h>

void mv(int* p, int num);

int main(void)
{
	int array[8] = { 1,2,3,4,5,6,7,8 };
	int i;


	printf("실행 전 : ");
	for (i = 0;i < 8;i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	mv(array, sizeof(array) / sizeof(int));
	

}

void mv(int* p, int num)
{
	int temp, i;

	temp = p[7];
	for (i = num-1;i > 0;i--)
	{
		p[i] = p[i - 1];
	}
	p[0] = temp;

	printf("실행 후 : ");
	for (i = 0;i < num;i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}