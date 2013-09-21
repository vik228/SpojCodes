#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long int N, K;
	scanf ("%lld%lld",&N,&K);
	long long val;
	long long sum = N*(2*K + N - 1LL);
	long long sum1 = 0;
	for (int i = 1; i < N; i++)
	{
		scanf ("%lld",&val);
		sum1+= val;

	}
	sum1*= 2*1LL;
	printf ("%lld\n",(sum - sum1)/2);
	return 0;

}
