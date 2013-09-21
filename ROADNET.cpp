#include <iostream>
#include <cstdio>
int graph[210][210];
using namespace std;
int main()
{
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		int n;
		scanf ("%d",&n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				scanf ("%d",&graph[i][j]);
		}
		int i, j,k;
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				bool found = true;
				for (int k = 0; k < n; k++)
				{
					if ((graph[i][j] == graph[i][k] + graph[k][j]) and (i != j) and (k != i) and (k != j))
					{
						//cout << i << "->" << j << " via " << k << "\n";
						found = false;
						break;
					}
				}
				if (found and i != j)
					printf ("%d %d\n",i+1, j+1);

			}
		}
	}
	return 0;
}
