#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
long long input[1000010];
using namespace std;
int main()
{
	long long T;
	long long N;
	scanf ("%lld",&T);
	long long j = 1;
	while (T--)
	{
		scanf ("%lld",&N);
		for (long long i = 0; i < N; i++)
		{
			scanf ("%lld",&input[i]);
		}
		long long sum = 0;
		long long ans = 0;
		bool val = false;
		for (long long i = 0; i < N; i++)
		{
			sum+= input[i];
			if (sum <= 0)
			{
				val = true;
				ans+= abs(sum) + 1;
				sum = 1;
			}

		}
		if(val)
			printf("Scenario #%lld: %lld\n",j,ans);
		else
		{
			int ans1 = 1;
			printf("Scenario #%lld: %d\n",j,ans1);
		}

		j++;

	}
	return 0;

}


