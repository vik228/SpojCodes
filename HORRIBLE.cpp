#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define MAX 100010
long long tree[3*MAX];
long long lazy[3*MAX];
void update (long long node, long long b, long long e, long long i, long long j, long long val)
{
	//cout << "hiii\n";
	if (lazy[node] != 0)
	{
		tree[node]+= (e-b+1)*lazy[node];
		if (b != e)
		{
			lazy[2*node]+=  lazy[node];
			lazy[2*node+1]+= lazy[node];
		}
		lazy[node] = 0;
	}
	if (b > e or j < b or i > e)
		return;
	if (b >= i and e <= j)
	{
		tree[node]+= (e-b+1)*val;
		if (b != e)
		{
			lazy[2*node]+=  val;
			lazy[2*node+1]+= val;
		}
		return ;
	}
	int mid = (b + e)/2;
	update (2*node, b, mid, i, j, val);
	update (2*node+1, mid+1, e,i,j,val);
	tree[node] = tree[2*node] + tree[2*node+1];

}
long long query(long long node, long long b, long long e, long long i, long long j)
{
	if (lazy[node] != 0)
	{
		tree[node]+= (e-b+1)*lazy[node];
		if (b != e)
		{
			lazy[2*node]+= lazy[node];
			lazy[2*node+1]+= lazy[node];
		}
		lazy[node] = 0;
	}
	if (b > e or b > j or i > e)
		return 0;
	if (b >= i and e <= j)
		return tree[node];
	int mid = (b+e)/2;
	long long p1 = query (2*node, b, mid, i, j);
	long long p2 = query (2*node+1, mid+1, e, i, j);
	return p1+p2;
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		long long N, C;
		memset (tree, 0, sizeof(tree));
		memset (lazy, 0 , sizeof(lazy));
		scanf ("%lld%lld",&N,&C);
		while (C--)
		{
			long long int q_type,i,j,val;
			scanf ("%lld",&q_type);
			if (q_type == 0LL)
			{
				scanf ("%lld%lld%lld",&i,&j,&val);
				update (1LL, 0LL, N-1, i-1, j-1, val);
			}
			if (q_type == 1LL)
			{
				scanf ("%lld%lld",&i,&j);
				/*
				for (int k = 0; k < 3*N; k++)
					cout << tree[k] << " ";
				cout << "\n";
				*/
				printf ("%lld\n",query(1LL,0LL,N-1,i-1,j-1));
			}
		}

	}
	return 0;
}
