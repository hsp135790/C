#include<stdio.h>

int solution(int n);

int main()
{
	int n, result;

	scanf("%d", &n);

	result = solution(n);

	printf("%d", result);
}

int solution(int n)
{
	int cnt = 0;

	while (1)
	{
		if (n != 1)
		{
			if (n % 2 == 0)
			{
				n = n / 2;
				cnt++;
			}
			else if (n % 2 == 1)
			{
				n = n * 3 + 1;
				cnt++;
			}
		}
		else if (cnt >= 500)
			break;

		else
			break;
				
	}

	return cnt;
}