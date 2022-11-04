#include<stdio.h>

int main()
{
	int a, i;
	int gugu[9];

	printf("Put num : ");
	scanf_s("%d", &a);

	for (i = 0;i < 9;i++)
	{
		gugu[i] = a * (i + 1);
		printf("%d x %d = %d\n", a, i + 1, gugu[i]);
	}
}