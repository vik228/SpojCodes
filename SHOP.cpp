#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
char graph[30][30];
bool visited[30][30];
int d[30][30];
#define INF 1000000
using namespace std;
int r, c;
struct G_Node
{
	int cd_x, cd_y, cost;
};
bool operator < (const G_Node& a, const G_Node& b)
{
	return b.cost < a.cost;
}
int bfs (int x, int y)
{
	//cout << "called \n";
	//cout << x << " : " << y << "\n";
	priority_queue< G_Node, vector<G_Node>, less <G_Node> > pq;
	G_Node a;
	//cout << "after 1\n";
	a.cd_x = x;
	//cout << "after 2\n";
	a.cd_y = y;
	//cout << "after 3\n";
	a.cost = 0;
	//cout << "after 4\n";
	d[x][y] = 0;
	//cout << "after 5\n";
	pq.push(a);
	//cout << "hii\n";
	while (!pq.empty())
	{
		//cout << "hello\n";
		G_Node b = pq.top();
		int c_x = b.cd_x;
		int c_y = b.cd_y;
		int cst = b.cost;
		visited[c_x][c_y] = true;
		d[c_x][c_y] = cst;
		pq.pop();
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if ((i == 1 and j == 1) or (i == -1 and j == -1) or (i == 1 and j == -1) or (i == -1 and j == 1))
					continue;
				int coord_x = c_x + i;
				int coord_y = c_y + j;
				//cout << coord_x << ":" << coord_y << "\n";
				if (coord_x < 0 or coord_x >= r)
					continue;
				if (coord_y < 0 or coord_y >= c)
					continue;
				//cout << "(" << coord_x << "," << coord_y << ")" << "\n";
				char c = graph[coord_x][coord_y];
				if (!visited[coord_x][coord_y] and c != 'X' and  (c - '0') + d[c_x][c_y] < d[coord_x][coord_y])
				{
					//cout << (c - '0') + d[c_x][c_y] << "\n";
					d[coord_x][coord_y] = (c - '0') + d[c_x][c_y];
					G_Node b;
					b.cd_x = coord_x;
					b.cd_y = coord_y;
					b.cost = d[coord_x][coord_y];
					pq.push (b);
					visited[coord_x][coord_y] = true;

				}

			}
		}
	}
}
int main()
{
	while (scanf ("%d%d",&c, &r))
	{
		if (r == 0 or c == 0)
			break;
		memset (d, 0, sizeof (d));
		memset (visited, 0, sizeof (visited));

		int s_x, s_y, d_x, d_y;
		for (int i = 0; i < r; i++)
		{
			scanf ("%s",&graph[i]);
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				d[i][j] = INF;
				if (graph[i][j] == 'S')
				{
					s_x = i;
					s_y = j;
				}
				if (graph[i][j] == 'D')
				{
					graph[i][j] = '0';
					d_x = i;
					d_y = j;
				}
			}
		}
		bfs (s_x, s_y);
		cout << d[d_x][d_y] << "\n";
	}
	return 0;
}

