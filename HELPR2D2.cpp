#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX 100000
#define TMAX 1 << 18
bool used[MAX + 10];
struct node 
{
	int min1;
	int max1;
}tree[TMAX];
void init (int node, int b, int e, int K)
{
	if (b == e)
	{
		tree[node].min1 = tree[node].max1 = K;
		return;
	}
	int mid = (b + e)/2;
	init (2*node, b, mid, K);
	init (2*node + 1 , mid + 1, e, K);
	tree[node].min1 = tree[node].max1 = K;
}
int update (int node, int b, int e, int v)
{
	if (tree[node].max1 < v)
		return -1;
	if (b == e)
	{
		tree[node].min1 -= v;
		tree[node].max1 -= v;
		return b;
	}
	int mid, ret_val;
	mid = (b + e)/2;
	ret_val = update (2*node, b, mid, v);
	if (ret_val == -1)
		ret_val = update (2*node + 1, mid+1, e, v);
	tree[node].min1 = min (tree[2*node].min1, tree[2*node + 1].min1);
	tree[node].max1 = max (tree[2*node].max1, tree[2*node + 1].max1);
	return ret_val;
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		memset (used, 0, sizeof (used));
		int K;
		scanf ("%d",&K);
		int n;
		scanf ("%d",&n);
		int r, v , sum = 0, cnt = 0;
		char s[20];
		init (1, 0, MAX-1, K);
		for (int i = 0; i < n; i++)
		{
			
			scanf ("%s",&s);
			if (s[0] != 'b')
			{
				v = 0;
				v = atoi (s);
				sum += v;
				int ans = update (1, 0 , MAX - 1, v);
				if (!used[ans])
				{
					cnt+= 1;
					used[ans] = true;
				}
				
			}
			else
			{
				scanf ("%d%d",&r, &v);
				sum += r*v;
				for (int t = 0; t < r; t++)
				{
					int ans = update (1, 0, MAX-1, v);
					if (!used[ans])
					{
						cnt++;
						used[ans] = true;
					}
				}
				i+= r-1;

			}

		}
		printf ("%d %d\n", cnt, ((cnt)*K - sum));

	}
}

