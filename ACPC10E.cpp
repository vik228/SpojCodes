#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define MAX 1 << 21
long long a[61];
void precompute ()
{
	for (long long i = 0; i <= 60; i++)
	{
		a[i] = 1LL<<i;
	}
}
int main()
{
	precompute ();
	/*
	for (int i = 0;  i <= 60; i++)
		cout << a[i] << " ";
	exit(0);
	*/
	long long G,A,T,D;
	while (scanf ("%lld%lld%lld%lld",&G,&T,&A,&D))
	{
		if (G == -1 or A == -1 or T == -1 or D == -1)
		{
			break;
		}
		long long t1 = G*A + D;
		//cout << t1 << "\n";
		int idx = (lower_bound (a, a + 60, t1) - a);
		//cout << idx << "\n";
		long long Y = a[idx] - t1;
		long long m1 = G*(T*(T-1)/2);
		long long X = m1 + (a[idx] - 1);
		printf ("%lld*%lld/%lld+%lld=%lld+%lld\n",G,A,T,D,X,Y);
	}
	return 0;

}
