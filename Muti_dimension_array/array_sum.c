#include<stdio.h>

int main()
{
	int house[3][3];
	int i, j, sum=0;

	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			printf("%d층 %d호의 가족은 몇 명입니까? : ",i+1,j+1);
			scanf_s("%d", &house[i][j]);
			sum = sum + house[i][j];
		}
	}
	printf("아파트 총 주민수는 %d명 입니다.\n", sum);
}