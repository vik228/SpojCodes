#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 2020
int bit[MAX][MAX];
int w[1020], v[1020];
int dp[1020][1020];
void update (int x, int y, int val, int N, int M)
{
	int y1;
	while (x <= N)
	{
		y1 = y;
		while (y1 <= M)
		{
			bit[x][y1] += val;
			y1 += (y1 & -y1); 
		}
		x += (x & -x); 
	}

}
int readsum(int x, int y)
{
	int v = 0, y1;
	while(x > 0)
	{
		y1 = y;
		while(y1 > 0)
		{
			v += bit[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return v;
}
int knapsack (int n, int W)
{
	for (int i = 0; i <= n; i++)
	{
		dp[i][0] = 0;
	}
	for (int i = 0; i <= W; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			if (w[i-1] > j)
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = max (dp[i-1][j], v[i - 1] + dp[i-1][j-w[i - 1]]);
			}
		}
	}
	return dp[n][W];
}
int readInt()
{
	int cc = getc(stdin);
	while (cc < '0' || cc > '9')
		cc = getc(stdin);
	int ret = 0;
	while (cc >= '0' && cc <= '9') {
		ret = ret * 10 + cc - '0';
		cc = getc(stdin);
	}
	return ret;
}
int main()
{
	int N, M, Q, K;
	N = readInt ();
	M = readInt ();
	Q = readInt ();
	K = readInt ();
	int val;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			val = readInt();
			update (i, j,val, N, M);
		}
	}
	int i = 0;
	while (Q--)
	{
		int x1, y1, x2, y2;
		scanf ("%d%d%d%d",&x1,&y1,&x2,&y2);
		int v1 = readsum (x1-1, y1-1);
		int v2 = readsum (x2, y2);
		int v3 = readsum (x2, y1 - 1);
		int v4 = readsum (x1-1, y2);
		w[i] = (v1-v3-v4+v2);
		v[i] = (x2 - x1 + 1)*(y2 - y1 + 1);
		i++;
	}
	printf ("%d\n",knapsack (i, K));
	return 0;
}
