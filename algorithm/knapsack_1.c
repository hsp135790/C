#include<stdio.h>
#include<string.h>
#define max(a,b) (a)>(b)?(a):(b);


int main()
{

	int w[101]; //무게
	int v[101]; //가치
	int dp[101]={NULL};
	int i, j;

	int N, K; //물품의 수 N, 버틸 수 있는 무게 K

	scanf("%d %d", &N, &K);

	for (i = 1;i <= N;i++)
	{
		scanf("%d %d",&w[i],&v[i]);
	}

	for (i = 1;i <= N;i++)
	{
		for (j = K;j >= 1;j--)
		{
			if (w[i] <= j)
			{
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
	}
	printf("%d", dp[K]);

	return 0;
}