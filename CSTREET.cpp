#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 1050
#define MAX1 300000
using namespace std;
struct graph
{
	int u1,v1,c1;
}g[MAX1];
int parent[MAX];
bool comp (graph g1, graph g2)
{
	//cout << "hi\n";
	return g1.c1 < g2.c1;
}
int find (int i)
{
	int j;
	for (j = i; parent[j] >= 0; j = parent[j]);
	return j;
}
int union1 (int i, int j)
{
	int root1 = find (i);
	int root2 = find (j);
	if (root1 != root2)
	{
		if (parent[root1] <= parent[root2])
		{
			parent[root1]+= parent[root2];
			parent[root2] = root1;
		}
		else
		{
			parent[root2]+= parent[root1];
			parent[root1] = root2;
		}
	}

}
long long krushkal (int n_e, int n_v)
{
	for (int i = 0; i < n_v; i++)
	{
		parent[i] = -1;
	}
	long long cst = 0;
	for (int i = 0; i < n_e; i++)
	{
		if (find (g[i].u1) != find(g[i].v1))
		{
			cst+= g[i].c1;
			union1(g[i].u1,g[i].v1);
		}
	}
	return cst;
}
int main()
{
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		int n,m;
		long long p;
		scanf ("%lld",&p);
		scanf ("%d",&n);
		scanf ("%d",&m);
		int a,b,c;
		for (int i = 1; i <= m; i++)
		{
			scanf ("%d%d%d",&a,&b,&c);
			g[i-1].u1 = a;
			g[i-1].v1 = b;
			g[i-1].c1 = c;
		}
		sort (g, g+m,comp);
		long long res = krushkal(m,n);
		printf ("%lld\n",res*p);
	}
	return 0;
}

