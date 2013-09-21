#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits.h>
#define MAX 110
using namespace std;
int dp[110][110], input[110][110];
int findMinFare (int N, int M)
{
	for (int i = 0; i < M; i++)
		dp[0][i] = input[0][i];
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (j == 0)
			{
				dp[i][j] = min (input[i][j] + dp[i-1][j], input[i][j] + dp[i-1][j+1]);
			}
			else if (j == M-1)
			{
				dp[i][j] = min (input[i][j] + dp[i-1][j], input[i][j] + dp[i-1][j-1]);
			}
			else
			{
				int a = input[i][j] + dp[i-1][j];
				int b = input[i][j] + dp[i-1][j-1];
				int c = input[i][j] + dp[i-1][j+1];
				dp[i][j] = min (min (a, b), min (b, c));
			}
		}
	}
	int ret_val = INT_MAX;
	for (int i = 0; i < M; i++)
	{
		ret_val = min (ret_val, dp[N-1][i]);
	}
	return ret_val;
}
int main()
{
	int N, M;
	scanf ("%d%d",&N,&M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			scanf ("%d",&input[i][j]);
	}
	printf ("%d\n",findMinFare(N, M));
	return 0;
}
