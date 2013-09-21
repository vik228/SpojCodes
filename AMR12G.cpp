#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char input[60][60];
pair <int, int> p1[60];
bool comp (pair <int, int> i, pair <int, int> j)
{
	return i.first > j.first;
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int N, M, K;
		scanf ("%d%d%d",&N,&M,&K);
		for (int i = 0; i < N; i++)
			p1[i].first = p1[i].second = 0;
		//memset (input, 0, sizeof(input));
		char ch;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> ch;
				if (ch == '.')
					p1[i].first+= 1;
				else if (ch == '*')
					p1[i].second+= 1;
			}
		}
		for (int i = 0; i < K; i++)
		{
			sort (p1, p1+N, comp);
			int t = p1[0].first;
			p1[0].first = p1[0].second;
			p1[0].second = t;
		}
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			ans+= p1[i].second;
		}
		printf ("%d\n",ans);

	}
	return 0;
}
