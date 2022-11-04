#include<stdio.h>

void swap(int** q1, int** q2);

int main(void)
{
	int a = 10, b = 20;
	int* p1 = NULL, * p2 = NULL;

	p1 = &a;
	p2 = &b;

	printf("----------Before the Call---------\n");
	printf("a = %d , b = %d \n", a, b);
	printf("*p1 = %d, *p2 = %d \n", *p1, *p2);

	swap(&p1, &p2);

	printf("----------After the Call---------\n");
	printf("a = %d , b = %d \n", a, b);
	printf("*p1 = %d, *p2 = %d \n", *p1, *p2);


	return 0;
}

void swap(int** q1, int** q2)
{
	int* temp;

	temp = *q1;
	*q1 = *q2;
	*q2 = temp;

}