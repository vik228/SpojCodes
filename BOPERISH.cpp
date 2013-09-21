#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int N;
	while (scanf ("%d",&N))
	{
		if (N == 0)
		{
			break;
		}
		int input[N];
		for (int i = 0; i < N; i++)
		{
			scanf ("%d",&input[i]);
		}
		sort (input, input+N);
		int i;
		for (i = N; i >= 1; i--)
		{
			if (input[N-i] >= i)
				break;
		}
		printf ("%d\n",i);

	}
}
