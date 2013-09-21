#include <iostream>
#include <cstdio>
#include <algorithm>
typedef long long int int64;
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int64 N;
		int K;
		scanf ("%lld",&N);
		scanf ("%d",&K);
		int64 salary[K],ans[K];
		int ai;
		for (int i = 0; i < K; i++)
		{
			scanf ("%d",&ai);
			if (i == 0)
				salary[i] = ai;
			else
				salary[i] = (salary[i-1]<<1) + ai;
				
		}
		int t = 0;
		for (int j = K - 1; j >= 0; j--)
		{
			if (salary[j] <= N)
			{
				ans[t++] = j + 1;
				N-= salary[j];
			}
		}
		//cout << t << "\n";
		if (N > 0)
			printf ("-1\n");
		else
		{
			for (int i = t - 1; i >= 0; i--)
			{
				//cout << "hii\n";
				printf ("%d ",ans[i]);
			}
			printf ("\n");
		}


	}
	return 0;
}
