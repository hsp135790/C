#include<stdio.h>

void rabbit(void);

int main(void)
{
	int i;

	for (i = 0;i < 12;i++)
		rabbit();

}

void rabbit(void)
{
	static int r1 = 1;
	static int r2 = 1;
	static int num;

	

	printf("%d\n", r1);
	num = r1 + r2;
	r1 = r2;
	r2 = num;
}