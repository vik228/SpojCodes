#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 1000000
unsigned flag[MAX >> 6];
#define ifc(n) (flag[(n)>>6]&(1<<(((n)>>1)&31)))
#define isc(n) (flag[(n)>>6]|=(1<<(((n)>>1)&31)))
#define MAX1 40050
int lazy[MAX1];
int tree[MAX1];
int input[10050];
void count_prime (int node, int b, int e, int val)
{
	if ((val % 2 == 0 and val != 2) or val == 1)
	{
		tree[node] = 0;
	}
	else if (val != 2)
	{
		int v = ifc(val);
		if (v == 0)
		{
			tree[node] = e-b+1;
		}
		else 
			tree[node] = 0;
	}
	else
		tree[node] = e-b+1;
}
void init (int node, int b, int e)
{
	if (b == e)
	{
		count_prime (node, b, e, input[b]);
		return;
	}
	int mid = (b + e)/2;
	init(2*node, b, mid);
	init (2*node+1,mid+1,e);
	tree[node] = tree[2*node] + tree[2*node +1];
}
void update (int node, int b, int e, int i, int j, int val)
{
	if (lazy[node] != 0)
	{
		count_prime (node, b, e, lazy[node]);
		if (b != e)
		{
			lazy[2*node] = lazy[node];
			lazy[2*node + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
	if (b > e or j < b or i > e )
	{
		return;
	}
	if (b >= i and e <= j)
	{
		count_prime (node, b, e, val);
		if (b != e)
		{
			lazy[2*node] = val;
			lazy[2*node+1] = val;
		}
		return;
	}
	int mid = (b + e)/2;
	update (2*node, b, mid, i, j, val);
	update (2*node + 1, mid+1,e,i, j, val);
	tree[node] = tree[2*node] + tree[2*node+1];
}
int query (int node, int b, int e, int i, int j)
{
	if (lazy[node] != 0)
	{
		count_prime(node, b, e, lazy[node]);
		if (b != e)
		{
			lazy[2*node] = lazy[node];
			lazy[2*node + 1] = lazy[node];
		}
		lazy[node] = 0;
	}
	if (b > e or j < b or i > e)
		return -1;
	if (b >= i and e <= j)
		return tree[node];
	int mid = (b + e)/2;
	int p1 = query (2*node, b, mid, i, j);
	int p2 = query (2*node+1, mid+1, e, i, j);
	if (p1 == -1)
		return p2;
	if (p2 == -1)
		return p1;
	return (p1+p2);
	
}
void sieve()
{
	unsigned i,j,k,q;
	for (i = 3; i*i <= MAX; i+= 2)
	{
		int v = ifc(i);
		if (v == 0)
		{
			for (j = i*i,k = i<<1; j < MAX; j+= k)
			{
				isc(j);
			}
		}
	}
}

int main()
{
	sieve();
	int T;
	sieve();
	scanf ("%d",&T);
	int cse = 0;
	while (T--)
	{
		cse++;
		int n,q;
		scanf ("%d%d",&n,&q);
		for (int i = 0; i < n; i++)
		{
			scanf ("%d",&input[i]);
		}
		memset (lazy, 0, sizeof(lazy));
		//memset (tree, 0, sizeof(tree));
		init (1,0, n-1);
		printf ("Case %d:\n",cse);
		while (q--)
		{
			int q_type;
			scanf ("%d",&q_type);
			if (q_type == 0)
			{
				int i,j,x;
				scanf ("%d%d%d",&i,&j,&x);
				update (1, 0, n-1, i-1, j-1,x);
			}
			else if (q_type == 1)
			{
				int i, j;
				scanf ("%d%d",&i,&j);
				printf ("%d\n",query (1,0, n-1,i-1,j-1)); 
			}
		}
	}
	return 0;
}
