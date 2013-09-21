#include <iostream>
#include <cstdio>
#include <set>
#include <set>
#include <cstring>
#include <vector>
#define MAX 40010
int parent[MAX];
bool visited[MAX];
using namespace std;
vector <int> ans;
void find (int M)
{
	int x, y;
	for (int i = 0; i < M; i++)
	{
		memset (visited, 0, sizeof(visited));
		
		scanf ("%d%d",&x,&y);
		int v1 = x;
		int v2 = y;
		while (1)
		{
			if (parent[v1] == -1)
			{
				visited[v1] = true;
				break;
			}
			visited[v1] = true;
			v1 = parent[v1];
		}
		int i_pt;
		while (1)
		{
			if (visited[v2] == true)
			{
				//cout << v2 << "\n";
				i_pt = v2;
				break;
			}
			visited[v2] = true;
			v2 = parent[v2];
		}
		ans.push_back (i_pt);
	}
}
int main()
{
	int T;
	scanf ("%d",&T);
	int cse = 0;
	while (T--)
	{
		cse++;
		int N;
		scanf ("%d",&N);
		memset (visited, 0, sizeof (visited));
		memset (parent, -1, sizeof (parent));
		for (int i = 1; i <= N; i++)
		{
			int nodes;
			scanf ("%d",&nodes);
			int v;
			for (int j = 0; j < nodes; j++)
			{
				scanf ("%d",&v);
				parent[v] = i;
			}

		}
		int Q;
		scanf ("%d",&Q);
		find (Q);
		printf("Case %d:\n",cse);
		for (int i = 0; i < ans.size(); i++)
			printf ("%d\n",ans[i]);
		ans.clear();

	}
	return 0;
}


