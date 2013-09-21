#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
	int N;
	scanf ("%d",&N);
	int ni;
	vector <int> v1;
	int max_val = 0;
	int max_idx = -1;
	for (int i = 0; i < N; i++)
	{
		scanf ("%d",&ni);
		v1.push_back (ni);
		if (max_val < ni)
		{
			max_val = ni;
			max_idx = i;
		}

	}
	int cnt = 1;
	for (int j = max_idx-1; j >= 0; j--)
	{
		if (v1[j] == max_val-1)
		{
			max_val = v1[j];
			cnt++;
		}
	}
	int ans = N - cnt;
	printf ("%d\n",ans);
	return 0;
}
