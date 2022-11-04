#include<stdio.h>

void Alpha(char k);

int main()
{


	char k;

	printf("알파벳을 입력하시오 : ");
	scanf_s("%c", &k);

	Alpha(k);
}

void Alpha(char k)
{
	if ((int)k >= 97 && (int)k <= 122)
		printf("입력한 %c는 알파벳 순서로 %d번째 문자입니다.\n", k, k-'a'+1);
	else
		printf("입력한 %c는 알파벳 순서로 %d번째 문자입니다.\n", k, k-'A'+1);
}