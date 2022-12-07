#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int M, N, K;
	int i, temp, sum=0;
	int num[100] = {NULL};
	
	scanf("%d %d", &M, &N);
	K = N - M;
	
	for (i = 0;i <= K;i++)
	{
		temp = sqrt(M + i);
		temp = pow(temp, 2);

		if (M + i == temp)
			num[i] = M + i;
		else
			num[i] = NULL;

	}
	
	for (i = 0;i <= K;i++)
	{
		if (num[i] == 0)
		{
			for (int j = i;j <= N - M;j++)
			{
				num[j] = num[j + 1];
			}
			K--;
			i--;
		}
	}
	for (i = 0; i <= K;i++)
	{
		sum = sum + num[i];

		if (num[i] == 0)
			break;
	}
	printf("%d\n%d\n",num[0], sum);


}
