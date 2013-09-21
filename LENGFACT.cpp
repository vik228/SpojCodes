#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		long long n;
		scanf ("%lld",&n);
		if (n == 1 || n == 0)
		{
			printf ("1\n");
			continue;
		}
		long long ans = (long long)((double)n*log10((double)n/M_E) + 0.5*log10(2*M_PI*n)) + 1;
		printf ("%lld\n",ans);
	
	}
	return 0;
}
