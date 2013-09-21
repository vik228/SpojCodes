#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int d;
	scanf ("%d",&d);
	while (d--)
	{
		long long n,m;
		scanf ("%lld%lld",&n,&m);
		printf("%d\n", 0 == ((n - m) & ((m - 1) >> 1)));
	}
	return 0;
}
