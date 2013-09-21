#include <iostream>
#include <cstdio>
#define INF 100000000
using namespace std;
struct seg_tree
{
	int min_range, max_range;
}tree[150000];
int A[50010];
void init (int n, int b, int e)
{
	if (b == e)
	{
		tree[n].min_range = tree[n].max_range = A[b];
		return;
	}
	int mid = b + (e - b)/2;
	init (2*n, b, mid);
	init (2*n + 1, mid+1, e);
	tree[n].min_range = min (tree[2*n].min_range, tree[2*n+1].min_range);
	tree[n].max_range = max (tree[2*n].max_range, tree[2*n +1].max_range);
}
void query (seg_tree &s1, int n, int b, int e, int i, int j)
{
	if (b > e or j < b or i > e)
	{
		s1.min_range = INF; s1.max_range = 0;
		return;
	}
	if (b >= i and e <= j)
	{
		s1 = tree[n];
		return;
	}
	seg_tree left, right;
	int mid = b + (e - b)/2;
	query (left, 2*n, b, mid, i, j);
	query (right, 2*n + 1, mid + 1, e, i, j);
	s1.min_range = min (left.min_range, right.min_range);
	s1.max_range = max (left.max_range, right.max_range);
}
int main()
{
	int N,Q;
	scanf ("%d%d",&N, &Q);
	for (int i = 0; i < N; i++)
	{
		scanf ("%d",&A[i]);
	}
	init (1,0,N-1);
	int A, B;
	while (Q--)
	{
		seg_tree s2;
		scanf ("%d%d",&A, &B);
		query (s2, 1, 0, N-1, A-1, B-1);
		//cout << s2.min_range << ":" << s2.max_range << "\n";
		printf ("%d\n",s2.max_range - s2.min_range);
	}
	return 0;
}
