#include <iostream>
#include <cstdio>
using namespace std;
long long cnt_bits (long long K)
{
	int c;
	for (c = 0; K ; c++)
	{
		K &= K-1;
	}
	return c;
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int N;
		long long K;
		scanf ("%d %lld",&N, &K);
		if (cnt_bits (K - 1)&1)
			printf ("Female\n");
		else
			printf ("Male\n");

	}
	return 0;
}
