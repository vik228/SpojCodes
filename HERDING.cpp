#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 1010
char grid[MAX][MAX];
int visited[MAX][MAX];
int R,C, cnt, traps;
void floodFill (int i, int j)
{
	if (i < 0 or j < 0 and i >= R or j >= C)
		return;
	if (visited[i][j] > 0)
	{
		cnt = visited[i][j];
		return;
	}
	visited[i][j] = cnt;
	if (grid[i][j] == 'S')
		floodFill (i + 1, j);
	if (grid[i][j] == 'N')
		floodFill (i - 1, j);
	if (grid[i][j] == 'E')
		floodFill (i, j + 1);
	if (grid[i][j] == 'W')
		floodFill (i, j - 1);
	visited[i][j] = cnt;
}
int main()
{
	scanf ("%d%d",&R,&C);
	for (int i = 0; i < R; i++)
		scanf ("%s",grid[i]);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (visited[i][j] == 0)
			{
				cnt = traps+1;
				floodFill (i,  j);
				if (cnt > traps)
					traps++;
			}

		}
	}
	printf ("%d\n",traps);
	return 0;
}
