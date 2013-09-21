#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		long long N;
		scanf ("%lld",&N);
		long long sum = 0;
		long long val;
		for (int i = 0; i < N; i++)
		{
			scanf ("%lld",&val);
			sum=  (sum + val)%N;
		}
		if (sum == 0)
			printf ("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
