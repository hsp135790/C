#include<stdio.h>

int main()
{
	int house[3][3];
	int i, j, sum=0;

	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 3;j++)
		{
			printf("%d�� %dȣ�� ������ �� ���Դϱ�? : ",i+1,j+1);
			scanf_s("%d", &house[i][j]);
			sum = sum + house[i][j];
		}
	}
	printf("����Ʈ �� �ֹμ��� %d�� �Դϴ�.\n", sum);
}