#include <iostream>
#include <cstdio>
#define MOD 1000000007
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int n;
		scanf ("%d",&n);
		unsigned long long fact = 1;
		for (int i = 1; i < n; i++)
		{
			fact = (fact*2)%MOD;
		}
		unsigned long long sum = 0;
		for (int i = 0; i < n; i++)
		{
			long long e;
			scanf ("%lld",&e);
			sum = (sum + e%MOD)%MOD;
		}
		unsigned long long total_sum = (fact*sum)%MOD;
		printf ("%lld\n",total_sum);
	}
	return 0;
}
