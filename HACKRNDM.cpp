#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
	int n,k;
	scanf ("%d%d",&n,&k);
	int A[n];
	for (int i = 0; i < n; i++)
	{
		scanf ("%d",&A[i]);

	}
	int ans = 0;
	sort (A,A+n);
	for (int i = 0; i < n - 1; i++)
	{
		if (binary_search(A,A+n,A[i] + k))
		{
			ans++;
		}

	}
	printf ("%d\n",ans);
	return 0;
}
