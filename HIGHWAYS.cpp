#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <queue>
#define INF 987654321
#define MAX 100010
using namespace std;
struct G_Node
{
	int to, cost;
};
bool operator< (const G_Node& a, const G_Node& b)
{
	return (b.cost < a.cost);
}
vector <G_Node> graph[MAX];
int d[MAX];
void dijkstra (int s, int t, int n)
{
	for (int i = 0; i < n; i++)
	{
		d[i] = INF;
	}
	priority_queue< G_Node, vector<G_Node>, less <G_Node> > pq;
	G_Node a;
	a.to = s;
	a.cost = 0;
	d[s] = 0;
	pq.push(a);
	while (!pq.empty())
	{
		G_Node b = pq.top();
		int u = b.to;
		int D = b.cost;
		pq.pop();
		if (D <= d[u])
		{
			for (int j = 0; j < graph[u].size(); j++)
			{
				int v = graph[u][j].to;
				int c = graph[u][j].cost;
				if (d[v] > d[u] + c)
				{
					d[v] = d[u] + c;
					G_Node b;
					b.to = v;
					b.cost = d[v];
					pq.push (b);
				}
			}
		}
	}


}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int n, m, s, t;
		scanf ("%d%d%d%d",&n,&m,&s,&t);
		for (int i = 0; i < n; i++)
			graph[i].clear();
		int u, v, c;
		for (int i = 0; i < m; i++)
		{
			scanf ("%d%d%d",&u,&v,&c);
			G_Node b;
			b.to = u-1;
			b.cost = c;
			graph[v-1].push_back (b);
			b.to = v-1;
			graph[u-1].push_back (b);
		}
		dijkstra (s-1, t-1, n);
		if (d[t-1] == INF)
			printf ("NONE\n");
		else
			printf ("%d\n",d[t-1]);

	}
}
