#include <iostream>
#include <cstdio>
using namespace std;
int dist[110][110];
int graph[110][110];
#define INF 987654321
void warshall (int N)
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			dist[i][j] = graph[i][j];
		}
	}
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}

	}

}
int main()
{
	int N, E, T, M;
	scanf ("%d%d%d%d",&N,&E,&T,&M);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			graph[i][j] = INF;
		}
	}
	int u, v, c;
	for (int i = 1; i <= N; i++)
		graph[i][i] = 0;
	for (int i = 1; i <= M; i++)
	{
		scanf ("%d%d%d",&u,&v,&c);
		graph[u][v] = c;
	}
	warshall (N);
	int cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (dist[i][E] <= T and dist[i][E] != INF)
		{
			//cout << dist[i][E] << "\n";
			//cout << i << "->" << E << "\n";
			cnt++;
		}
	}
	printf ("%d\n",cnt);
	return 0;
}
