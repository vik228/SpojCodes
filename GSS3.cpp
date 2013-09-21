#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#define MAX 1 << 16
int A[MAX];
using namespace std;
struct seg_tree
{
	int suffix_sum,prefix_sum,c_sum,max_sum;
}tree[MAX << 1];
int max3 (int a, int b, int c)
{
	return (max (a, max (b,c)));
}
void init (int n, int b, int e)
{
	if (b == e)
	{
		tree[n].suffix_sum = tree[n].prefix_sum = tree[n].c_sum = tree[n].max_sum = A[b];
		return;
	}
	int mid = (b + e)/2;
	init (2*n, b, mid);
	init (2*n + 1, mid+1, e);
	tree[n].suffix_sum = max (tree[2*n].suffix_sum + tree[2*n+1].c_sum, tree[2*n+1].suffix_sum);
	tree[n].prefix_sum = max (tree[2*n].prefix_sum,  tree[2*n].c_sum + tree[2*n +1].prefix_sum);
	tree[n].max_sum = max3 (tree[2*n].max_sum, tree[2*n + 1].max_sum, tree[2*n].suffix_sum + tree[2*n+1].prefix_sum);
	tree[n].c_sum = tree[2*n].c_sum + tree[2*n + 1].c_sum;
}
void update (int n, int b, int e, int idx, int val)
{
	if (b == e)
	{
		tree[n].suffix_sum = tree[n].prefix_sum = tree[n].c_sum = tree[n].max_sum = val;
		return;
	}
	int mid = (b + e)/2;
	if (idx <= mid)
		update (2*n, b, mid, idx, val);
	else
		update (2*n + 1, mid+1, e, idx, val);
	tree[n].suffix_sum = max (tree[2*n].suffix_sum + tree[2*n + 1].c_sum, tree[2*n+1].suffix_sum);
	tree[n].prefix_sum = max (tree[2*n].prefix_sum , tree[2*n].c_sum + tree[2*n +1].prefix_sum);
	tree[n].max_sum = max3 (tree[2*n].max_sum, tree[2*n + 1].max_sum, tree[2*n].suffix_sum + tree[2*n+1].prefix_sum);
	tree[n].c_sum = tree[2*n].c_sum + tree[2*n + 1].c_sum;
}
void query (seg_tree &ret_val,int n, int b, int e, int i, int j)
{
	if (b == i and e == j)
	{
		ret_val = tree[n];
		return;
	}
	int mid = (b + e)/2;
	if (j <= mid)
	{
		query (ret_val,2*n, b, mid, i, j);
	}
	else if (i > mid)
	{
		query (ret_val,2*n + 1, mid+1, e, i, j);
	}
	else
	{
		seg_tree left, right;
		query (left, 2*n, b, mid, i, mid);
		query (right,2*n + 1, mid + 1, e, mid + 1, j);
		ret_val.suffix_sum = max (left.suffix_sum + right.c_sum, right.suffix_sum);
		ret_val.prefix_sum = max (left.prefix_sum,  left.c_sum + right.prefix_sum);
		ret_val.c_sum = left.c_sum + right.c_sum;
		ret_val.max_sum = max3 (left.max_sum, right.max_sum, left.suffix_sum + right.prefix_sum);

	}
}
int main()
{
	int N;
	scanf ("%d",&N);
	for (int i = 0; i < N; i++)
	{
		scanf ("%d",&A[i]);
	}
	init (1,0,N-1);
	int M;
	scanf ("%d",&M);
	int q,x,y;
	while (M--)
	{
		seg_tree ret_val;
		scanf ("%d%d%d",&q,&x,&y);
		if (q == 0)
		{
			update (1,0,N-1,x-1,y);	
		}
		else
		{
			query (ret_val,1,0,N-1,x-1,y-1);
			printf ("%d\n",ret_val.max_sum);
		}
	}
	return 0;
}
