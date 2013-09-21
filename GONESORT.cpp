#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 100010
int input[MAX];
int LIS (int n)
{
	int lis[n+1];
	for (int i = 0; i < n; i++)
		lis[i] = 1;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((input[i] ==  input[j] + 1) and (lis[i] <= lis[j]))
			{
				lis[i] = lis[j]+1;
			}
		}
	}
	int ret_val = lis[0];
	for (int i = 1; i < n; i++)
		ret_val = max (ret_val, lis[i]);
	return ret_val;
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int N;
		scanf ("%d",&N);
		for (int i = 0; i < N; i++)
			scanf ("%d",&input[i]);
		int lis = LIS(N);
		int ans = N - lis;
		printf ("%d\n",ans);
	}
}
