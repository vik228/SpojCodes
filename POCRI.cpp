#include <iostream>
#include <cstdio>
using namespace std;
int josephus (int n, int k)
{
	if (n == 1)
		return 1;
	else
		return ((josephus (n-1, k) + k - 1) % n + 1);
}
int main()
{
	int N;
	while (scanf ("%d",&N))
	{
		if (N == 0)
			break;
		for (int i = 0; i <= 250; i++)
		{
			if (josephus (N-1, i) == 12)
			{
				printf ("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
