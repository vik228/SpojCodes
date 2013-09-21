#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#define MAX 120
using namespace std;
set <int> graph[MAX];
vector <int> order;
set <int> Q;
int indeg[MAX];
void topoSort ()
{
	set <int>::iterator it;
	while (!Q.empty())
	{
		int v = *Q.begin();
		order.push_back (v);
		Q.erase (Q.begin());
		for (it = graph[v].begin(); it != graph[v].end(); it++)
		{
			int u = *it;
			indeg[u]--;
			if (indeg[u] == 0)
				Q.insert (u);
		}
	}
}
int main()
{
	int N, M, k, v, u;
	scanf ("%d%d",&N, &M);
	for (int i = 0; i < M; i++)
	{
		scanf ("%d%d",&v, &k);
		for (int i = 0; i < k; i++)
		{
			scanf ("%d",&u);
			graph[u].insert (v);
		}
		indeg[v] += k; 
	}
	for (int i = 1; i <= N; i++)
	{
		if (indeg[i] == 0)
		{
			Q.insert (i);
		}
	}
	topoSort ();
	for (int i = 0; i < order.size(); i++)
	{
		printf ("%d ", order[i]);
	}
	return 0;
}
