#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
const double PI =  acos(-1.0); 
#define MAX 10001
double PIE[MAX];
using namespace std;
bool pred (double val, int F, int N)
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		cnt+= (int)floor(PIE[i]/val);
	}
	if (cnt >= F + 1 )
		return true;
	else
		return false;
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int N,F;
		int r;
		scanf ("%d%d",&N,&F);
		for (int i = 0; i < N; i++)
		{
			scanf ("%lf",&PIE[i]);
			PIE[i] = (PIE[i]*PIE[i])*PI;
		}
		sort (PIE, PIE+N);
		double low = 0;
		double high = PIE[N-1];
		int t = 0; 
		while (t < 45)
		{
			double mid = low + (high - low)/2;
			if (pred(mid,F, N))
			{
				//cout << "hii\n";
				low = mid;
			}
			else
				high = mid;
			t++;
		}
		printf ("%0.4lf\n",low);

	}
}
