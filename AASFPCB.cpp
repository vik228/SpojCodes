#include <iostream>
#include <cstdio>
int dp[12][1010];
int coins[12];
#define INF 1000000
using namespace std;
int main()
{
	int C,N;
	scanf ("%d%d",&C,&N);
	for (int i = 1; i <= N; i++)
	{
		scanf ("%d",&coins[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		dp[i][0] = 0;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (i == 1 and j < coins[i])
				dp[i][j] = INF;
			else if (i == 1)
				dp[i][j] = 1 + dp[i][j - coins[i]];
			else if (j < coins[i])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = min (dp[i-1][j], 1 + dp[i][j - coins[i]]);
		}
	}
	printf ("%d\n",dp[N][C]);
	return 0;
}

