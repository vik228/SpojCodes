#include <iostream>
#include <cstdio>
#define MAX 100010
using namespace std;
int input[MAX];
int merge (int p, int q, int r, int tmp[])
{
	int start = p, end = q, mid = r;
	int j = mid + 1;
	int k = p;
	int count = 0;
	for (int i = start; i <= mid; i++)
	{	
		while (j <= end)
		{
			if (input[i] > input[j])
			{
				//count++;
				j++;
			}
			else
				break;

		}
		count+= j - (mid+1);
		//j = mid+1;
	}
	j = mid+1;
	while (start <= mid and j <= end)
	{
		if (input[start] <= input[j])
			tmp[k++] = input[start++];
		else
			tmp[k++] = input[j++];
	}
	while (start <= mid)
		tmp[k++] = input[start++];
	while (j <= end)
		tmp[k++] = input[j++];
	for (int t = p; t <= q; t++)
		input[t] = tmp[t];
	return count;

}
int ret_count(int i, int j,int tmp[])
{
	int p,q,r;
	if (i >= j)
		return 0;
	int mid = (i + j)/2;
	int lc = ret_count (i,mid,tmp);
	int rc = ret_count (mid + 1, j,tmp);
	int mc = merge (i,j,mid,tmp);
	return (lc + rc + mc);

}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int N;
		scanf ("%d",&N);
		int tmp[N];
		for (int i = 0; i < N; i++)
			scanf ("%d",&input[i]);
		int res = ret_count(0,N-1,tmp);
		printf ("%d\n",res);

	}
	return 0;
}
