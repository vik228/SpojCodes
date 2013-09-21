#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int N1;
		scanf ("%d",&N1);
		int alt1[N1];
		for (int i = 0; i < N1; i++)
		{
			scanf ("%d",&alt1[i]);
		}
		int N2;
		scanf ("%d",&N2);
		int alt2[N2];
		for (int i = 0; i < N2; i++)
		{
			scanf ("%d",&alt2[i]);
		}
		//sort (alt1, alt1+N1);
		//sort (alt2, alt2+N2);
		int min1 = 100000007;
		for (int i = 0; i < N1; i++)
		{
			for (int j = 0; j < N2; j++)
			{
				min1 = min (abs(alt1[i] - alt2[j]), min1);
			}
		}

		/*
		for (int k = 0; k < min (N1, N2); k++)
		{
			if (abs (alt1[i+1] - alt2[j]) < abs (alt1[i] - alt2[j+1]))
			{
				min1 = abs (alt1[i+1] - alt2[j]);
				i++;
			}
			else
			{
				min1 = abs (alt1[i] - alt2[j+1]);
				j++;
			}
		}
		*/
		printf ("%d\n",min1);
	}
	return 0;
}
