#include<stdio.h>

void Alpha(char k);

int main()
{


	char k;

	printf("���ĺ��� �Է��Ͻÿ� : ");
	scanf_s("%c", &k);

	Alpha(k);
}

void Alpha(char k)
{
	if ((int)k >= 97 && (int)k <= 122)
		printf("�Է��� %c�� ���ĺ� ������ %d��° �����Դϴ�.\n", k, k-'a'+1);
	else
		printf("�Է��� %c�� ���ĺ� ������ %d��° �����Դϴ�.\n", k, k-'A'+1);
}