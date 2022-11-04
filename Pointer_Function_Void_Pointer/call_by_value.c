#include<stdio.h>
void func(char c, char* str, int num1, double num2);

int main(void)
{
	char c = 'A';
	char* str = "ABCD";
	int num1 = 10;
	double num2 = 3.14;

	func(c, str, num1, num2);
	

	return 0;
}

void func(char c, char* str, int num1, double num2)
{
	printf("%c ", c);
	printf("%s ", str);
	printf("%d ", num1);
	printf("%.2lf \n", num2);
}