#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector <int> v;
int ans[1010][1010];
int solve (int sum, int i, int k, int n)
{
	if (i >= n)
		return sum;

	if (ans[i][sum] != -1)
		return ans[i][sum];

	if (sum+v[i] > k)
		ans[i][sum] = solve (sum, i+1, k, n);
	else
		ans[i][sum] = max (solve (sum, i+1, k, n), solve (sum+v[i], i+2, k, n));
	return ans[i][sum];
	
}
int main()
{
	int T;
	scanf ("%d",&T);
	int cse = 0;
	while (T--)
	{
		cse++;
		v.clear();
		memset (ans, -1, sizeof (ans));
		int N, K;
		scanf ("%d%d",&N,&K);
		for (int i = 0; i < N; i++)
		{
			int val;
			scanf ("%d",&val);
			v.push_back (val);
		}
		solve (0, 0, K, N);
		printf ("Scenario #%d: %d\n",cse, solve (0, 0, K, N));

	}
	return 0;
}
