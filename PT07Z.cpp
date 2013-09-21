#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 10000
bool visited[MAX];
vector <int> graph[MAX];
int d[MAX];
int bfs (int i, int N)
{
	queue<int> Q;
	Q.push (i);
	d[i] = 0;
	visited[i] = true;
	while (!Q.empty())
	{
	//	cout << "hii\n";
		int u = Q.front();
		Q.pop();
		for (int i = 0; i < graph[u].size(); i++)
		{
			int v = graph[u][i];
			if (!visited[v])
			{
				d[v] = d[u] + 1;
				Q.push (v);
				visited[v] = true;
			}
		}
	}
	return (max_element (d, d + (N + 1)) - d);
}
int main()
{
	int N;
	scanf ("%d",&N);
	int u, v;
	for (int i = 0; i < N - 1; i++)
	{
		scanf ("%d%d",&u,&v);
		graph[u-1].push_back (v - 1);
		graph[v-1].push_back (u - 1);
	}
	int ret_val = bfs (0, N);
	//cout << ret_val << "\n";
	memset (d, 0, sizeof (d));
	memset (visited, 0, sizeof (visited));
	//cout << bfs (ret_val, N) << "\n";
	printf ("%d\n",d[bfs (ret_val, N)]);
	return 0;
}

