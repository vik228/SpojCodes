#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 120
#define INF 1000000000
using namespace std;
struct dp
{
	int cost;
	int val;
}dp[MAX][MAX];
int vals[MAX];
int min_smoke (int n)
{
	for (int i = 1; i <= n; i++)
	{
		dp[i][i].cost = 0;
		dp[i][i].val = vals[i-1];
	}
	for (int l = 2; l <= n; l++)
	{
		for (int i = 1; i <= n-l+1; i++)
		{
			int j = i + l - 1;
			dp[i][j].cost = INF;
			for (int k = i; k < j; k++)
			{
				int q = dp[i][k].cost + dp[k+1][j].cost + dp[i][k].val*dp[k+1][j].val;
				if (q < dp[i][j].cost)
				{
					dp[i][j].cost = q;
					dp[i][j].val = (dp[i][k].val + dp[k+1][j].val)%100;
				}
			}

		}
	}
	return dp[1][n].cost;
}
int main ()
{
	int n;
	while (scanf ("%d",&n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			scanf ("%d",&vals[i]);
		}
		printf ("%d\n",min_smoke(n));
	}
	return 0;
}

