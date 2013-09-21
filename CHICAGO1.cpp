#include <iostream>
#include <cstdio> 
#include <cstring>
double graph[110][110];
using namespace std;
void floyd_warshall (int V)
{
	for (int i = 1; i <=  V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			for (int k = 1; k <= V; k++)
			{
				graph[j][k] = max (graph[j][i]*graph[i][k], graph[j][k]);
			}
		}
	}
}
int main()
{
	int V, E;
	while (scanf ("%d%d",&V,&E))
	{
		if (V == 0 or E == 0)
		{
			break;
		}
		int u, v, c;
		memset (graph, 0, sizeof(graph));
		for (int i = 1; i <= E; i++)
		{
			scanf ("%d%d%d",&u,&v,&c);
			graph[u][v] = (double)c/100.00;
			graph[v][u] =(double)c/100.00;
		}
		floyd_warshall (V);
		printf("%.6lf percent\n",graph[1][V]*100.00);
	}
}


