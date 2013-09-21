#include <iostream>
#include <cstdio>
#define MOD 1000000000
using namespace std;
int main()
{
	int n;
	scanf ("%d",&n);
	long long dp[n];
	dp[0] = 3;
	dp[1] = 7;
	for (int i = 2; i < n; i++)
	{
		dp[i] = (dp[i-2]%MOD + (2*dp[i-1])%MOD)%MOD;
	}
	printf ("%lld\n",dp[n-1]%MOD);
	return 0;
}
