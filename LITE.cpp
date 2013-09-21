#include <iostream>
#include <cstdio>
#define MAX 100010
using namespace std;
struct seg_tree
{
	int status;
	int count;
}tree[3*MAX];
void update (int node, int b, int e, int i, int j)
{
	//cout << "updating \n";
	if (i == b and j == e)
	{
		tree[node].status ^= 1;
		tree[node].count = (e - b + 1) - tree[node].count;
		return;
	}
	int mid = (b + e) >> 1;
	if (j <= mid)
		update (node << 1, b, mid, i, j);
	else if (i > mid)
		update (2*node + 1, mid + 1, e, i, j);
	else
	{
		update (2*node, b, mid, i, mid);
		update (2*node + 1, mid + 1, e, mid + 1 , j);
	}
	if (tree[node].status)
		tree[node].count = (e - b + 1) - tree[2*node].count - tree[2*node+1].count;
	else
		tree[node].count = tree[2*node].count + tree[2*node + 1].count;
}
int query (int node, int b, int e, int i, int j)
{
	if (i == b and j == e)
	{
		return tree[node].count;
	}
	int ret_val;
	int mid = (b + e) >> 1;
	if (j  <= mid )
		ret_val = query (node << 1, b, mid, i, j);
	else if (i > mid)
		ret_val = query (2*node + 1, mid + 1, e, i, j);
	else
	{
		ret_val = query (node << 1, b, mid, i, mid);
		ret_val += query (2*node + 1, mid + 1, e, mid + 1 , j);
	}
	if (tree[node].status)
		return (j - i +1 - ret_val);
	return ret_val;
	
}
int main()
{
	int N, M;
	scanf ("%d%d",&N, &M);
	int q_type, i, j;
	while (M--)
	{
		scanf ("%d%d%d",&q_type, &i, &j);
		if (q_type == 0)
		{
			update (1, 0, N-1, i-1, j-1);
			for (int i = 0; i < 3*N; i++)
				cout << "( " << tree[i].status << "," << tree[i].count << ")" << " ";
		}
		else 
			printf ("%d\n", query (1, 0, N-1, i-1, j-1));
		cout << "\n";
	}
	return 0;
}
