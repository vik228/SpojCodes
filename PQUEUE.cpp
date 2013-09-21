#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
bool comp (pair <int, int> p1, pair <int, int> p2)
{
	return p1.first >= p2.first;
}
int main()
{
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		int n, m;
		queue < pair <int, int> > Q;
		scanf ("%d%d",&n,&m);
		int priority;
		pair <int, int> p[n + 1];
		for (int i = 0; i < n; i++)
		{
			scanf ("%d",&priority);
			p[i] = make_pair (priority, i);
			pair <int, int> p1 = make_pair (i, priority);
			Q.push (p1);
		}
		sort (p, p + n, comp);
		int j = 0;
		int cnt = 0;
		while (1)
		{
			int idx = p[j].second;
			while (Q.front().first != idx and Q.front().second != p[j].first)
			{
				//cout << idx << "\n";
				pair <int, int> p2 = Q.front();
				Q.push(p2);
				Q.pop();
			}
			j++;
			cnt += 1;
			pair <int, int> p2 = Q.front();
			Q.pop();
			if (p2.first == m)
				break;
		}
		printf ("%d\n",cnt);
	}
	return 0;
}

