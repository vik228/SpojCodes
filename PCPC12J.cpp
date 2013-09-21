#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		int n;
		scanf ("%d",&n);
		map < int, int > m1,m2;
		map <int, int>::iterator it;
		pair <int, int> p1[n];
		int ai;
		for (int i = 0; i < n; i++)
		{
			scanf ("%d",&ai);
			m1[ai]+= 1;
		}
		int idx = 0;
		for (it = m1.begin(); it != m1.end(); it++)
		{
			if (((it->second) % (it->first)) == 0)
			{
				p1[idx].first = it->first;
				p1[idx].second = it->second;
				idx++;
			}
		}
		if (idx == 0)
			printf ("-1\n");
		else
		{
			int max_val = p1[0].second;
			int val = p1[0].first;
			for (int i = 1; i < idx; i++)
			{
				if (p1[i].second > max_val)
				{
					max_val = p1[i].second;
					val = p1[i].first;
				}
			}
			printf ("%d\n",val);
		}
		
		
	}
	return 0;
}
