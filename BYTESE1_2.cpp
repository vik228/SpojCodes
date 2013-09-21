#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int graph[120][120];
int d[120][120];
bool visited[120][120];
int M, N;
#define INF 10000000
struct G_Node
{
	int c_x, c_y, cost;
};
bool operator< (const G_Node& a, const G_Node& b)
{
	return b.cost < a.cost;
}
void dijkstra (int i, int j)
{
	priority_queue< G_Node, vector<G_Node>, less <G_Node> > pq;
	G_Node a;
	a.c_x = i;
	a.c_y = j;
	a.cost = graph[i][j];
	d[i][j] = graph[i][j];
	pq.push (a);
	while (!pq.empty())
	{
		G_Node a = pq.top();
		int x = a.c_x;
		int y = a.c_y;
		int cst = a.cost;
		visited[x][y] = true;
		d[x][y] = cst;
		pq.pop();
		for (int cx = -1; cx <= 1; cx++)
		{
			for (int cy = -1; cy <= 1; cy++)
			{
				int coord_x = x + cx;
				int coord_y = y + cy;
				if (coord_x < 0 or coord_x >= M)
					continue;
				if (coord_y < 0 or coord_y >= N)
					continue;
				if (coord_x == x + 1 and coord_y == y + 1)
					continue;
				if ((coord_x == x + 1 and coord_y == y - 1) or (coord_x == x - 1 and coord_y == y + 1) or (coord_x == x - 1 and coord_y == y - 1))
					continue;
				int c = graph[coord_x][coord_y];
				if (!visited[coord_x][coord_y] and (c+d[x][y] < d[coord_x][coord_y]))
				{
					d[coord_x][coord_y] = c + d[x][y];
					G_Node b;
					b.c_x = coord_x;
					b.c_y = coord_y;
					b.cost = d[coord_x][coord_y];
					pq.push(b);
					visited[coord_x][coord_y] = true;
					
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
		scanf ("%d%d",&M,&N);
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf ("%d",&graph[i][j]);
				d[i][j] = INF;
				visited[i][j] = false;
			}
		}
		dijkstra (0, 0);
		int s, t, time1;
		scanf ("%d %d %d",&s,&t,&time1);
		int val = d[s-1][t-1];
		//cout << val << "\n";
		if (val < time1)
		{
			printf ("YES\n%d\n",(time1 - val));
		}
		else
			printf ("NO\n");
	}
	return 0;
	
}
