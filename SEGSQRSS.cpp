#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 300010
using namespace std;
struct tree
{
	long long sqr_sum;
	long long cum_sum;
}tree[MAX];
struct lazy
{
	int val;
	int type_update;
	bool is_updated;
}lazy[MAX];
int input[MAX];
void init (int node, int b, int e)
{
	if (b == e)
	{
		tree[node].sqr_sum = (long long)input[b]*input[b];
		tree[node].cum_sum = 1LL*input[b];
		return;
	}
	int mid = (b + e)/2;
	init (2*node, b, mid);
	init (2*node+1,mid+1,e);
	tree[node].sqr_sum = tree[2*node].sqr_sum + tree[2*node + 1].sqr_sum;
	tree[node].cum_sum = tree[2*node].cum_sum + tree[2*node+1].cum_sum;
}
void update_node (int node, int b, int e, int update_type)
{
		if (update_type == 1)
		{
			tree[node].sqr_sum += (long long)(e-b+1)*lazy[node].val*lazy[node].val + (long long)2*lazy[node].val*tree[node].cum_sum;
			tree[node].cum_sum +=  (long long)(e-b+1)*lazy[node].val;
			if (b != e)
			{
				lazy[2*node].val+= lazy[node].val;
				lazy[2*node+1].val+= lazy[node].val;
				lazy[2*node].type_update = 1;
				lazy[2*node+1].type_update = 1;

				lazy[2*node].is_updated = true;
				lazy[2*node+1].is_updated = true;


			}
			lazy[node].is_updated = false;

		}
		else
		{
			tree[node].sqr_sum = (long long)(e-b+1)*lazy[node].val*lazy[node].val;
			tree[node].cum_sum = (long long)(e-b+1)*lazy[node].val;
			if (b != e)
			{
				lazy[2*node].val = lazy[node].val;
				lazy[2*node + 1].val = lazy[node].val;
				lazy[2*node].type_update = 0;
				lazy[2*node+1].type_update = 0;
				lazy[2*node].is_updated = true;
				lazy[2*node+1].is_updated = true;
			}
			lazy[node].is_updated = false;
		}

}
void update (int node, int b, int e, int i, int j, int value, int update_type)
{
	if (lazy[node].is_updated)
	{
		update_node(node, b, e, update_type);
	}
	if (b > e or j < b or i > e)
		return;
	if (b >= i and e <= j)
	{
		if (update_type == 1)
		{
			tree[node].sqr_sum+= (long long)(e-b+1)*value*value + (long long)2*value*tree[node].cum_sum;
			tree[node].cum_sum+= (long long)(e-b+1)*value;
			if (b != e)
			{
				lazy[2*node].val += value;
				lazy[2*node+1].val += value;
				lazy[2*node].type_update = 1;
				lazy[2*node+1].type_update = 1;
				lazy[2*node].is_updated = true;
				lazy[2*node+1].is_updated = true;
			}
			return;
		}
		else
		{
			tree[node].sqr_sum = (long long) (e-b+1)*value*value;
			tree[node].cum_sum = (long long) (e-b+1)*value;
			if (b != e)
			{
				lazy[2*node].val = value;
				lazy[2*node+1].val = value;
				lazy[2*node].type_update = 0;
				lazy[2*node+1].type_update = 0;
				lazy[2*node].is_updated = true;
				lazy[2*node+1].is_updated = true;
			}
			return;
		}
			
	}
	int mid = (b + e)/2;
	update (2*node, b, mid, i, j, value, update_type);
	update (2*node+1, mid+1, e, i, j, value, update_type);
	tree[node].sqr_sum = tree[2*node].sqr_sum + tree[2*node+1].sqr_sum;
	tree[node].cum_sum = tree[2*node+1].cum_sum + tree[2*node+1].cum_sum;
}
long long query (int node, int b, int e, int i, int j)
{
	if (lazy[node].is_updated)
	{
		update_node (node, b, e, lazy[node].type_update);
	}
	if (b > e or j < b or i > e)
		return -1;
	if (b >= i and e <= j)
		return tree[node].sqr_sum;
	int mid = (b + e)/2;
	long long left = query (2*node, b, mid, i, j);
	long long right = query (2*node+1,mid+1,e,i,j);
	if (left == -1)
		return right;
	if (right == -1)
		return left;
	return (left+right);
}
int main()
{
	int T;
	scanf ("%d",&T);
	int cse = 0;
	while (T--)
	{
		cse++;
		int N, Q;
		memset (lazy, 0, sizeof(lazy));
		memset (tree, 0, sizeof(tree));
		memset (input, 0, sizeof (input));
		scanf ("%d%d",&N,&Q);
		for (int i = 0; i < N; i++)
		{
			scanf ("%d",&input[i]);
		}
		init (1, 0, N-1);
		//cout << query (1, 0, N-1, 0, N-1) << "\n";
		printf ("Case %d:\n",cse);
		while (Q--)
		{
			int q_type,i,j,x;
			scanf ("%d",&q_type);
			//cout << "q_type " << q_type << "\n";
			if (q_type == 0 or q_type == 1)
			{
				scanf ("%d%d%d",&i,&j,&x);
				update (1, 0, N-1, i-1,j-1,x,q_type);
			}
			else if (q_type == 2)
			{
				//cout << "hii\n";
				scanf ("%d%d",&i,&j);
				printf ("%lld\n",query (1,0,N-1,i-1,j-1));
			}
		}
	}
	return 0;
}
