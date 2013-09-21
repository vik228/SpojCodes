#include <iostream>
#include <algorithm>
#include <cstdio>
long long heights[20001];
using namespace std;
int main()
{
	int T,N,K;
	scanf ("%d",&T);
	while (T--)
	{
		scanf ("%d%d",&N,&K);
		for (int i = 0; i < N; i++)
			scanf ("%lld",&heights[i]);
		sort (heights, heights + N);
		if (K == 1)
		{
			printf ("0\n");
		}
		else if (K == N)
		{
			long long ans = heights[N-1] - heights[0];
			printf ("%lld\n",ans);
		}
		else
		{
			long long min_diff;
			long long ans;
			int i;
			for (i = 0; i < (N - K + 1); i++)
			{
				//cout << i + K -1 << "\n";
				ans = heights[i + K - 1] - heights[i];
				//cout << ans << "\n";
				if (i == 0)
				{
					min_diff = ans;
					//cout << min_diff << "\n";
				}
				else if (ans < min_diff)
				{
				
					min_diff = ans;
					//cout << min_diff << "\n";
				}
			}
			//cout << min_diff << "\n";
			printf ("%lld\n",min_diff);

		}

	}
	return 0;

}
