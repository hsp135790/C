#include<stdio.h>
#include<math.h>

int square(int n);
int cube(int n);
int quartic(int n);
int quintic(int n);

int main()
{
	int n1=1, n2=2, n3=3;
	int sn1, sn2, sn3;
	int cn1, cn2, cn3;
	int fn1, fn2, fn3;
	int qn1, qn2, qn3;

	sn1 = square(n1);
	sn2 = square(n2);
	sn3 = square(n3);

	cn1 = cube(n1);
	cn2 = cube(n2);
	cn3 = cube(n3);

	fn1 = quartic(n1);
	fn2 = quartic(n2);
	fn3 = quartic(n3);

	qn1 = quintic(n1);
	qn2 = quintic(n2);
	qn3 = quintic(n3);


	printf("A TABLE OF POWERS\n");
	printf("----------------------------------------------------------\n");
	printf("   INTEGER      SQUARE      CUBE      QUARTIC      QUINTIC\n");
	printf("----------------------------------------------------------\n");
	printf("        %d            %d         %d            %d            %d\n", n1, sn1, cn1, fn1, qn1);
	printf("        %d            %d         %d           %d           %d\n", n2, sn2, cn2, fn2, qn2);
	printf("        %d            %d        %d           %d          %d\n", n3, sn3, cn3, fn3, qn3);


}

int square(int n)
{
	return pow(n, 2);
}

int cube(int n)
{
	return pow(n, 3);
}

int quartic(int n)
{
	return pow(n, 4);
}

int quintic(int n)
{
	return pow(n, 5);
}