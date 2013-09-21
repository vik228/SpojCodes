#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits.h>
using namespace std;
int dp[201][201],val[201][201];
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		memset (dp,0,sizeof(dp));
		memset (val,0,sizeof(val));
		int h,w;
		scanf ("%d%d",&h,&w);
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				scanf ("%d",&val[i][j]);
			}
		}
		int ans = INT_MIN;
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				int c1 = dp[i-1][j-1] + val[i-1][j-1];
				int c2 = dp[i-1][j] + val[i-1][j-1];
				int c3 = dp[i-1][j+ 1] + val[i-1][j-1];
				int max1 = c1;
				if (c2 > max1)
					max1 = c2;
				if (c3 > max1)
					max1 = c3;
				dp[i][j] = max1;
				ans = max (ans,max1);

			}
		}
		/*
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= w; j++)
			{
				cout << dp[i][j] << "\t";

			}
			cout << "\n";
		}
		*/
		printf ("%d\n",ans);
	}
	return 0;

}
