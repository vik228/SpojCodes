#include <iostream>
#include <cstdio>
#define MOD 1000007
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		long long n;
		scanf ("%lld",&n);
		long long ans;
		ans = (n*(3*n + 1))/2;
		ans%=MOD;
		printf ("%d\n",ans);

	}
	return 0;
}
