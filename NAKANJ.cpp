#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define INF 1000000
using namespace std;
bool visited[10][10];
int dist[10][10];
bool isValid (int i, int j)
{
	if (i < 0 or i >= 8)
		return false;
	if (j < 0 or j >= 8)
		return false;
	if (visited[i][j])
		return false;
	return true;
}
void bfs (int i, int j)
{
	//cout << i << " " << j << "\n";
	queue < pair <int, int> > Q;
	Q.push (make_pair (i, j));
	visited[i][j] = true;
	dist[i][j] = 0;
	while (!Q.empty())
	{
		//cout << Q.size() << "\n";
		//cout << "hiii\n";
		pair <int, int> p1;
		p1 = Q.front();
		int x = p1.first;
		int y = p1.second;
		Q.pop();
		//cout << "bye\n";
		//cout << x << " " << y << "\n";
		if (isValid (x + 2, y + 1))
		{
			Q.push (make_pair (x+2, y + 1));
			dist[x+2][y+1] = dist[x][y] + 1;
			visited[x+2][y+1] = true;
		}	
		if (isValid (x + 2, y - 1))
		{
			Q.push (make_pair (x+2, y-1));
			dist[x+2][y-1] = dist[x][y] + 1;
			visited[x+2][y-1] = true;
		}
		if (isValid (x - 2, y - 1))
		{
			Q.push (make_pair (x - 2, y - 1));
			dist[x-2][y-1] = dist[x][y] + 1;
			visited[x-2][y-1] = true;
		}
		if (isValid (x - 2, y + 1))
		{
			Q.push (make_pair (x - 2, y + 1));
			dist[x-2][y+1] = dist[x][y] + 1;
			visited[x-2][y+1] = true;
		}
		if (isValid (x + 1, y + 2))
		{
			Q.push (make_pair (x+1, y + 2));
			dist[x+1][y+2] = dist[x][y] + 1;
			visited[x+1][y+2] = true;
		}
		if (isValid (x + 1, y - 2))
		{
			Q.push (make_pair (x + 1, y - 2));
			dist[x+1][y-2] = dist[x][y] + 1;
			visited[x+1][y-2] = true;
		}
		if (isValid (x - 1, y + 2))
		{
			Q.push (make_pair (x - 1, y + 2));
			dist[x-1][y+2] = dist[x][y] + 1;
			visited[x-1][y+2] = true;
		}
		if (isValid (x - 1, y - 2))
		{
			Q.push (make_pair (x - 1, y - 2));
			dist[x-1][y-2] = dist[x][y] + 1;
			visited[x-1][y-2] = true;
		}
	}
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		memset (visited, 0, sizeof (visited));
		memset (dist, 0, sizeof (dist));
		/*
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
				dist[i][j] = INF;
		}
		*/
		char from[3];
		char to[3];
		scanf ("%s%s",&from, &to);
		bfs ((from[0] - 'a'), (from[1] - '0' - 1));
		cout << dist[(to[0] - 'a')][(to[1] - '0' - 1)] << "\n";

	}
	return 0;
}


