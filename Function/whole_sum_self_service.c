#include<stdio.h>

int sum(int n);

int main()
{
	int n, result;
	
	printf("Input your number : ");
	scanf_s("%d", &n);

	result = sum(n);

	printf("1���� %d ������ �� : %d", n, result);
	return 0;

}

int sum(int n)
{
	if (n <= 1)
		return 1;

	return n + sum(n - 1);

}