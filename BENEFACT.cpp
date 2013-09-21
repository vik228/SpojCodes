#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
int visited[50010];
int dist[50010];
using namespace std;
struct node
{
	int i,d;
}graph_node;
int n;
vector <node> graph[50010];
int bfs (int u)
{
	for (int i = 0; i < n + 1; i++)
	{
		dist[i] = 0;
		visited[i] = 0;
	}
	queue<int> q1;
	q1.push(u);
	while (!q1.empty())
	{
		//cout << "hii\n";
		int v = q1.front();
		q1.pop();
		if (visited[v] == 0)
			visited[v] = 1;
		for (int it = 0; it < graph[v].size(); it++)
		{
			if (visited[graph[v][it].i] == 0)
			{
				visited[graph[v][it].i] == 1;
				q1.push(graph[v][it].i);
				dist[graph[v][it].i]+= dist[v] + graph[v][it].d;

			}

		}
	}
	return int(max_element (dist, dist+n+1) - dist);

}
int main()
{
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		//int n;
		scanf ("%d",&n);
		int a, b, l;
		for (int i = 1; i <= n; i++)
			graph[i].clear();
		for (int i = 0; i < n -1; i++)
		{
			scanf ("%d%d%d",&a,&b,&l);
			graph_node.i = a;
			graph_node.d = l;
			graph[b].push_back(graph_node);
			graph_node.i = b;
			graph[a].push_back (graph_node);
		}
		int node1 = bfs(1);
		printf ("%d\n",dist[bfs(node1)]);


	}
	return 0;
}
