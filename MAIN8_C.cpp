#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define MAX 50000
int input[MAX];
bool pred (int val, int N, int F)
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		cnt+= input[i]/val;
	}
	return (cnt >= F);
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int N, F;
		scanf ("%d%d",&N,&F);
		int high = 0, low = 1;
		for (int i = 0; i < N; i++)
		{
			scanf ("%d",&input[i]);
			if (high < input[i])
				high = input[i];
		}
		high+= 1;
		sort (input, input + N);
		if (F == 1)
		{
			printf ("%d\n",high - 1);
			continue;
		}
		int mid;
		while (low < high)
		{
			mid = low + (high - low)/2;
			if (pred(mid,N,F))
				low = mid + 1;
			else
				high = mid;
		}
		printf ("%d\n",low - 1);
	}
	return 0;
}
