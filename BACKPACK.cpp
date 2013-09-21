#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
int dp[61][32001];
using namespace std;
struct backpack
{
	int itm_no,att,vol,imp;
}b[60],b_attch[60];
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int W,N;
		scanf ("%d%d",&W,&N);
		int v,c,u;
		int it_no = 0;
		int t1,t2;
		t1 = t2 = 0;
		for (int i = 0; i < N; i++)
		{
			scanf ("%d%d%d",&v,&c,&u);
			it_no++;
			if (u == 0)
			{
				b[t1].itm_no = it_no;
				b[t1].att = u;
				b[t1].vol = v;
				b[t1].imp = c;
				t1++;
			}
			else
			{
				b_attch[t2].itm_no = it_no;
				b_attch[t2].att = u;
				b_attch[t2].vol = v;
				b_attch[t2].imp = c;
				t2++;
			}


		}
		int t = 0;
		memset(dp, 0, sizeof(dp[0][0]) * 61 * 32001);
		for (int i = 1; i <= t1; i++)
		{
			for (int j = 1; j <= W; j++)
			{
				if (b[i-1].vol > j)
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					int c1 = (b[i-1].vol)*(b[i-1].imp);
					int left = j - b[i-1].vol;
					int val = c1 + dp[i-1][left];
					dp[i][j] = max (val, dp[i-1][j]);
					int k = 0;
					pair <int,int> p1[N];
					for (int p = 0; p < t2; p++)
					{
						if (b_attch[p].att == b[i-1].itm_no and b_attch[p].vol <= left)
						{
							p1[k].first = b_attch[p].vol*b_attch[p].imp;
							p1[k].second = b_attch[p].vol;
							k++;
						}
					}
					int vol_used = b[i-1].vol;
					int imp = c1;
					for (int mask = 1; mask < (1<<k); mask++)
					{
						for (int k1 = 0; k1 < k; k1++)
						{
							if (mask & (1<<k1))
							{
								imp+= p1[k1].first;
								vol_used+= p1[k1].second;
							}
						}
						//cout << imp << ":" << j - vol_used << "\n";
						if ((j - vol_used) >= 0)
						{
							dp[i][j] = max (dp[i][j], imp + dp[i - 1][j-vol_used]);
						}
						vol_used = b[i-1].vol;
						imp = c1;
					}


				}
			}
		}
		printf ("%d\n",dp[t1][W]);

	}
	return 0;
}

