#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
bool visited[755][755];
int graph[755][755];
int W, H;
int bfs (int x, int y)
{
	//cout << "hii\n";
	queue < pair <int, int> > q1;
	q1.push(make_pair(x,y));
	int ret_val = 1;
	visited[x][y] = true;
	while (!q1.empty())
	{
		//cout << "hii\n";
		pair <int, int> p1 = q1.front();
		int cord_x = p1.first;
		int cord_y = p1.second;
		q1.pop();
		for (int c_x = -1; c_x <= 1; c_x++)
		{
			for (int c_y = -1; c_y <= 1; c_y++)
			{
				int x_val = cord_x + c_x;
				int y_val = cord_y + c_y;
				if (x_val < 0 or x_val >= W)
					continue;
				if (y_val < 0 or y_val >= H)
					continue;
				if (!visited[x_val][y_val] and graph[x_val][y_val] == '.')
				{
					q1.push(make_pair(x_val, y_val));
					ret_val++;	
					visited[x_val][y_val] = true;
				}
			}
		}

	}
	return ret_val;
}
int main()
{
	scanf ("%d%d",&W,&H);
	memset (visited,0, sizeof(visited));
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			cin >> graph[i][j];
		}

	}
	#ifdef DEBUG
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			//printf ("%c \t",graph[i][j]); 
			cout << graph[i][j] << " \t";
		}
		cout << "\n";
	}
	exit(0);
	#endif
	int sum = 10000007;
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < H; j++)
		{
			if (!visited[i][j] and graph[i][j] == '0')
			{
				sum = min(sum, bfs(i,j));
				//cout << sum << "\n";
			}
		}
	}
	printf ("%d\n",sum);
	return 0;


}
