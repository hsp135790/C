#include<stdio.h>

int Add(int x, int y);
void Count(int k);

int main(void)
{
	int x, y;

	while (1)
	{
		int c;
		printf("Put two nums : ");
		scanf_s("%d %d", &x, &y);

		c = Add(x, y);
		
		
		if (x == 0 && y == 0)
		{
			Count(c);
			break;
		}

	}
}

int Add(int x, int y)
{
	static int i;
	int result;
	result = x + y;

	printf("The answer is : %d\n", result);

	i = i + 1;

	return i;

}
void Count(int k)
{
	printf("Total number of operation is : %d\n", k-1);

}