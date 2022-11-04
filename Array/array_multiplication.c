#include<stdio.h>

int main()
{
	double a[5] = { 2.2,3.5,2.5,10.2,4.0 };
	double b[5] = { 3.3,2.0,4.0,1.0,2.5 };
	double m[5];
	int i;

	for (i = 0;i < 5;i++)
	{
		m[i] = a[i] * b[i];
		printf("%d 번째 요소의 곱 : %.2lf\n", i + 1, m[i]);
	}
}