#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct graph
{
	int u, v, c;
}node[1000000];
int parent[10010];
bool comp (graph c1, graph c2)
{
	return c1.c < c2.c;
}
bool is_present (int u, int v, int t)
{
	for (int i = 0; i < t; i++)
	{
		if ((node[i].u == u and node[i].v == v) or (node[i].u == v and node[i].v == u))
		{
			//cout << "hiii\n";
			return true;
		}
	}
	return false;
}
void init (int n_v)
{
	for (int i = 0; i <= n_v; i++)
		parent[i] = -1;
}
int find (int i)
{
	int j;
	for (j = i; parent[j] >= 0; j = parent[j]);
	return j;
}
void union1(int i, int j)
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
int krushkal (int n_e)
{
	int cst = 0;
	for (int i = 0; i < n_e; i++)
	{
		//cout << node[i].u << "->" << node[i].v << "\n";
		if (find(node[i].u) != find (node[i].v))
		{
			//cout << node[i].u << "->" << node[i].v << "\n";
			cst+= node[i].c;
			union1 (node[i].u, node[i].v);
		}
	}
	return cst;
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int n;
		scanf ("%d",&n);
		init (n);
		int min_cost = 0;
		int t = 0;
		for (int i = 1; i <= n; i++)
		{
			string s;
			cin >> s;
			int u = i;
			int neigh;
			//memset (parent, 0, sizeof (parent));
			scanf ("%d",&neigh);
			int v,c;
			for (int j = 0; j < neigh; j++)
			{
				node[t].u = u;
				scanf ("%d%d",&node[t].v,&node[t].c);
				t++;
				//cout << node[j].u << "->" << node[j].v << "->" << node[j].c << "\n";
			}
		}
		sort (node, node + t, comp);
		#ifdef DEBUG 
		for (int i = 0; i < t; i++)
		{
			cout << node[i].u << "->" << node[i].v << "->" << node[i].c << "\n";
		}
		#endif
		printf ("%d\n",krushkal (t));
	}
	return 0;
}
