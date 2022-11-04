#include<stdio.h>

int main()
{
	char* string[2] = { "I Love C","Hello World" };
	char* p[2] = { string[0],string[1]};

	

	printf("%s%s\n", p[0],p[1]+5);

}