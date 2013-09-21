#include <iostream>
#include <cstdio>
using namespace std;
int dist[25][25];
int s_dist[25][25];
int warshall[25][25];
bool isPossible (int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			warshall[i][j] = dist[i][j];
	}
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				warshall[i][j] = min (warshall[i][j], warshall[i][k] + warshall[k][j]);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			if (s_dist[i][j] != warshall[i][j])
				return false;
	}
	return true;
}
int main()
{
	int N;
	scanf ("%d",&N);
	int idx1, idx2;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf ("%d",&dist[i][j]);
			if (dist[i][j] == -1)
			{
				idx1 = i;
				idx2 = j;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf ("%d",&s_dist[i][j]);
	}
	int val = s_dist[idx1][idx2];
	int cnt = 0;
	for (int i = val; i <= 100; i++)
	{
		dist[idx1][idx2] = i;
		if (isPossible(N))
			cnt++;
	}
	printf ("%d\n",cnt);
	return 0;
}
