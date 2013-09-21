#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <limits.h>
#include <cstring>
using namespace std;
int dp[22][5];
int input[22][5];
int findMinCost (int n)
{
	for (int i = 0; i < 3; i++)
	{
		dp[0][i] = input[0][i];
	}
	int i, j;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{	
			int min_val = INT_MAX;
			for (int k = 0; k < 3; k++)
			{
				if (k != j and n > 2)
				{
					min_val = min (min_val, dp[i-1][k] + input[i][j]);
				}
				else if (n == 2)
					min_val = min (min_val, dp[i-1][k] + input[i][j]);
			}
			dp[i][j] = min_val;
		}
	}
	int ret_val = INT_MAX;
	for (int i = 0; i < 3; i++)
		ret_val = min (ret_val, dp[n-1][i]);
	return ret_val;
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int n;
		scanf ("%d",&n);
		for (int i = 0; i < n; i++)
		{
			scanf ("%d %d %d",&input[i][0], &input[i][1], &input[i][2]);
		}
		printf ("%d\n", findMinCost (n));
	}
}
			
