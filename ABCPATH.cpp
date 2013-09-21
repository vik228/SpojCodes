#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
char grid[60][60];
bool visited[60][60];
int dist[60][60];
using namespace std;
int H, W;
int bfs (int i, int j)
{
	queue< pair<int, int> > Q;
	Q.push (make_pair (i, j));
	visited[i][j] = true;
	dist[i][j] = 1;
	int path_len = 1;
	while (!Q.empty())
	{
		pair <int, int> p1;
		p1  = Q.front();
		int x = p1.first;
		int y = p1.second;
		visited[x][y] = true;
		Q.pop();
		for (int c_x = -1; c_x <= 1; c_x++)
		{
			for (int c_y = -1; c_y <= 1; c_y++)
			{
				int coord_x = c_x + x;
				int coord_y = c_y + y;
				if (coord_x < 0 or coord_x >= H)
					continue;
				if (coord_y < 0 or coord_y >= W)
					continue;
				int val1 = (int)grid[coord_x][coord_y];
				int val2 = (int)grid[x][y];
				if (!visited[coord_x][coord_y] and val1 == val2 + 1)
				{
					dist[coord_x][coord_y] = 1 + dist[x][y];
					visited[coord_x][coord_y] = true;
					path_len = max (path_len, dist[coord_x][coord_y]);
					Q.push (make_pair (coord_x, coord_y));
				}
			}
		}
	}
	return path_len;
}
int main()
{
	int cse = 0;
	while (scanf ("%d%d",&H,&W))
	{
		cse++;
		if (H == 0 or W == 0)
			break;
		for (int i = 0; i < H; i++)
		{
			scanf ("%s",&grid[i]);
		}
		int ans = 0;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (grid[i][j] == 'A')
				{
					//cout << i << " : " << j << "\n";
					memset (visited, 0, sizeof (visited));
					memset (dist, 0, sizeof (dist));
					ans = max (ans, bfs (i, j));

				}
			}
		}
		printf ("Case %d: %d\n", cse, ans);

	}
	return 0;
}
