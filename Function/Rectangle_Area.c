#include<stdio.h>

void getArea(int x, int y);

int main()
{
	int x, y;

	printf("Base length : ");
	scanf_s("%d", &x);
	printf("height : ");
	scanf_s("%d", &y);

	getArea(x, y);
}

void getArea(int x, int y)
{
	int a;
	a = x * y;
	printf(" Area of the Rectangle is : %d", a);
}
