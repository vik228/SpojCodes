#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
	int N;
	scanf ("%d",&N);
	long long pi;
	long long ans = 0;
	for (int i = 0; i < N; i++)
	{
		scanf ("%lld",&pi);
		ans^= pi;
	}
	printf ("%lld\n",ans);
	return 0;

}
