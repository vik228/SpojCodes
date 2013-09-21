#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MAX 100000
int input[MAX];
using namespace std;
bool pred (int val, int C, int N)
{
	int last_position = input[0];
	int p = 1;
	for (int i = 1; i < N; i++)
	{
		if (input[i] - last_position >= val)
		{
			p++;
			last_position = input[i];
		}
	}
	if (p >= C)
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
		int N, C;
		scanf ("%d%d",&N,&C);
		for (int i = 0; i < N; i++)
			scanf ("%d",&input[i]);
		sort (input, input + N);
		int low = 0;
		int high = input[N-1];
		//cout << high << "\n";
		while (low < high)
		{
			int mid = low + (high - low)/2;
			if (pred(mid, C, N))
			{
				low = mid+1;
			}
			else
			{
				//cout << "mid "  << mid << "\n";
				//cout << "low " << low << "\n";
				high = mid;
			}
				
		}
		printf ("%d\n",low - 1);


	}
	return 0;
}
