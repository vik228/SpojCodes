#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#define MAX 1 << 16
int A[MAX];
using namespace std;
struct seg_tree
{
	int prefix_sum;
	int suffix_sum;
	int cum_sum;
	int max_sum;
}tree[MAX << 1];

int max3(int a, int b, int c)
{
	return (max(a, max(b,c)));
}
void init (int n, int b, int e)
{
	if (b == e)
	{
		tree[n].prefix_sum = tree[n].suffix_sum = tree[n].cum_sum = tree[n].max_sum = A[b];
		return;
	}
	int mid = (b+e)/2;
	init (2*n, b, mid);
	init (2*n + 1, mid+1, e);
	tree[n].cum_sum = tree[2*n].cum_sum + tree[2*n + 1].cum_sum;
	tree[n].prefix_sum = max (tree[2*n].prefix_sum, tree[2*n].cum_sum + tree[2*n + 1].prefix_sum);
	tree[n].suffix_sum = max (tree[2*n].suffix_sum + tree[2*n + 1].cum_sum, tree[2*n + 1].suffix_sum);
	tree[n].max_sum = max3(tree[2*n].max_sum, tree[2*n+1].max_sum, tree[2*n].suffix_sum + tree[2*n +1].prefix_sum);
}
void query (seg_tree &ret_val, int n, int b, int e, int i, int j)
{
	if (i == b and j == e)
	{
		ret_val = tree[n];
		return;
	}
	int mid = (b + e)/2;
	if (j <= mid)
		query (ret_val,2*n,b,mid,i,j);
	else if (i > mid)
		query (ret_val,2*n + 1,mid + 1, e, i, j);
	else
	{
		seg_tree lft,rt;
		query (lft, 2*n, b, mid, i, mid);
		query (rt, 2*n + 1, mid + 1, e, mid + 1, j);
		ret_val.max_sum = max3 (rt.max_sum,lft.max_sum,lft.suffix_sum + rt.prefix_sum);
		ret_val.cum_sum = rt.cum_sum + lft.cum_sum;
		ret_val.prefix_sum = max (lft.prefix_sum, lft.cum_sum + rt.prefix_sum);
		ret_val.suffix_sum = max (lft.suffix_sum + rt.cum_sum, rt.suffix_sum);
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
	int x, y;
	while (M--)
	{
		seg_tree ret_val;
		scanf ("%d%d",&x,&y);
		query (ret_val,1,0,N-1,x-1,y-1);
		printf ("%d\n",ret_val.max_sum);
	}
}
