#include<stdio.h>

void* add(int a, int b);
void* substract(int a, int b);
void* multiply(int a, int b);
void* divide(int a, int b);

int main(void)
{
	int a, b;

	int* p = NULL;

	printf("Put two nums :");
	scanf("%d %d", &a, &b);

	p = add(a,b);
	p = substract(a, b);
	p = multiply(a, b);
	p = divide(a, b);



	return 0;
}

void* add(int a, int b)
{
	int result;
	result = a + b;
	printf("%d \n", result);
}

void* substract(int a, int b)
{
	int result;
	result = a - b;
	printf("%d \n", result);
}

void* multiply(int a, int b)
{
	int result;
	result = a * b;
	printf("%d \n", result);

}

void* divide(int a, int b)
{
	int result;
	result = a / b;
	printf("%d \n", result);
}