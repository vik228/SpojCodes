#include <iostream>
#include <cstdio>
#include <cstring>
int tri[100000][3];
#define inf 0x7f7f7f7f
using namespace std;
int main()
{
	int n;
	int cse = 0;
	while (scanf ("%d",&n))
	{
		memset (tri, 0, sizeof (tri));
		cse++;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				scanf ("%d",&tri[i][j]);
			}
		}
		tri[0][0] = inf;
		tri[0][2] += tri[0][1];
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				int a = (j == 2)? inf : tri[i-1][j + 1];
				int b = tri[i-1][j];
				int c = (j == 0) ? inf : tri[i-1][j-1];
				int d = (j == 0) ? inf : tri[i][j-1];
				tri[i][j] += min (min (a, b), min (c, d));
			}
		}
		printf ("%d. %d\n", cse, tri[n-1][1]);

	}
}
