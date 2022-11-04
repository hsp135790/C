#include<stdio.h>

int abs(int n);

int main(void)
{
	int n;

	printf("Put num : ");
	scanf_s("%d", &n);

	abs(n);

	return 0;

}

int abs(int n)
{
	if (n > 0)
		printf("absolute value is : %d\n", n);
	else
		printf("absolute value is : %d\n", -n);
}