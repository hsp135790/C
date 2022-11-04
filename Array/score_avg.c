#include<stdio.h>

int main()
{
	int score[10];
	int i,size,total=0;

	size = sizeof(score) / sizeof(int);

	for (i = 0;i < size;i++)
	{
		printf("%d 번째 학생의 점수를 입력하시오 : ",i+1);
		scanf_s("%d", &score[i]);
		total = total + score[i];
	}
	printf("\n");
	printf("Whole sum : %d\n", total);
	printf("Average : %.2lf\n", (double)total / size);
	
}