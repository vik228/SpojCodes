#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int input[60][60];
void floydWarshall (int N)
{
	int i, j, k;
	for (k = 0; k < N; k++)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				input[i][j] = min (input[i][j], (input[i][k] + input[k][j]));
			}
		}
	}
}
int main()
{
	int T;
	scanf ("%d",&T);
	int cse = 0;
	while (T--)
	{
		memset (input, 0, sizeof (input));
		cse++;
		int N;
		scanf ("%d",&N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf ("%d",&input[i][j]);
			}
		}
		floydWarshall (N);
		int R;
		int ans = 0;
		scanf ("%d",&R);
		while (R--)
		{
			int i, j;
			scanf ("%d%d",&i,&j);
			ans += input[i-1][j-1];
			
		}
		printf ("Case #%d: %d\n",cse, ans);
	}
	return 0;
}
