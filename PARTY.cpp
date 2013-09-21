#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int W,n;
	while (scanf ("%d%d",&W,&n))
	{
		if (W == 0 or n == 0)
			break;
		int V[n + 1][W + 1];
		int ans[n + 1][W + 1];
		int v[n + 1],w[n + 1];
		for (int i = 1;i <= n; i++)
		{
			scanf ("%d",&w[i]);
			scanf ("%d",&v[i]);
		}
		for (int i = 0; i <= n; i++)
		{
			V[i][0] = 0;
			//keep[i][0] = 0;
		}
		for (int j = 0; j <= W; j++)
		{
			V[0][j] = 0;
			//keep[0][j] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= W; j++)
			{
				if (w[i] > j)
				{
					V[i][j] = V[i - 1][j];
					ans[i][j] = ans[i - 1][j];;
				}
				else
				{
					int x = (v[i] + V[i-1][j - w[i]]);
					int y = V[i - 1][j];
					if (x > y)
					{
						V[i][j] = x;
						ans[i][j] = w[i] + ans[i-1][j - w[i]];
					}
					else if ( x == y)
					{
						V[i][j] = x;
						ans[i][j] = min(ans[i - 1][j],ans[i - 1][j - w[i]] + w[i]);
					}
					else
					{
						V[i][j] = y;
						ans[i][j] = ans[i - 1][j];
					}


				}
			}
		}
		printf ("%d %d\n",ans[n][W],V[n][W]);

	}
	return 0;
}
