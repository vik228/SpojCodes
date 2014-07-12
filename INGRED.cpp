#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 100000000
int graph[110][110];
int dist[110][110];
vector <int> v1;
void floydWarshall (int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dist[i][j] = graph[i][j];
		}
	}
	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if ((dist[i][k] + dist[k][j]) < dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}
int findMinCost (vector <int>& set, int source)
{
	int min_cost = 100000000;
	sort (set.begin(), set.end());
	do
	{
		int cost = 0;
		int src = source;
		for (int i = 0; i < set.size(); i++)
		{
			cost += dist[src][set[i]];
			src = set[i];
		}
		min_cost = min (cost, min_cost);
	}while (next_permutation (set.begin(), set.end()));
	return min_cost;
}
int calculate (int s1, int s2)
{
	int ans = 100000000;
	for (int i = 0; i < (1 << v1.size()); i++)
	{
		vector <int> set1, set2;
		for (int j = 0; j < v1.size(); j++)
		{
			if (i&(1<<j))
			{
				set1.push_back (v1[j]);
			}
			else
				set2.push_back (v1[j]);
		}
		int min1 = findMinCost (set1, s1);
		int min2 = findMinCost (set2, s2);
		ans = min (ans, (min1+min2));
	}
	return ans;
}
int main()
{
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			graph[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		graph[u][v] = c;
		graph[v][u] = c;
	}
	floydWarshall (n);
	int s;
	cin >> s;
	for (int i = 0; i < s; i++)
	{
		int val;
		cin >> val;
		v1.push_back (val);
	}
	int s1, s2;
	cin >> s1 >> s2;
	cout << calculate (s1, s2) << "\n";

}
