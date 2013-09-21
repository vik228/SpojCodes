#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int N;
		scanf ("%d",&N);
		long long ans1 = 1;
		long long ans2 = 1;
		long long val;
		vector <long long> v1;
		for (int i = 0; i < N; i++)
		{
			scanf ("%lld", &val);	
			v1.push_back (val);
		}
		sort (v1.begin(), v1.end());
		for (int i = N-1; i >= 0; i--)
		{
			//cout << ans1 << "=" << ans1%MOD << "*" << "(" << v1[i] - (long long)i << ")" << "\n";
			ans1 = (ans1%MOD)*(v1[i] - (long long)i)%MOD;
			//cout << ans1 << "\n";
		}
		printf ("%lld\n", ans1);
	}
	printf ("KILL BATMAN\n");
	return 0;
}
