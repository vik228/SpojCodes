#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 100010
int input[MAX];
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	int k = 0;
	while (T--)
	{
		k++;
		int X;
		int n;
		scanf ("%d%d",&X,&n);
		for (int i = 0; i < n; i++)
			scanf ("%d",&input[i]);
		sort (input, input+n);
		long long cnt = 0;
		for (int i = 0; i < n; i++)
		{	
			int val = X - input[i];
			int lb = lower_bound (input + i +1, input + n, val) - (input + i);
			int ub = upper_bound (input + i+1, input + n, val) - (input + i);
			//cout << "cnt " << cnt << "\n";
			cnt+= (long long)ub - lb;
		}
		printf ("%d. %lld\n",k,cnt);
	}
	return 0;
}



