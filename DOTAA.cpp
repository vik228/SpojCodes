#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		vector <int> v1;
		vector <int>::iterator it;
		int n,m,D;
		scanf ("%d%d%d",&n,&m,&D);
		int d_n;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			scanf ("%d",&d_n);
			if (d_n > D)
			{
				v1.push_back(d_n);
				cnt++;
			}
		}
		if (cnt >= m)
			printf ("YES\n");
		else
		{
			int cnt1 = 0;
			for (it = v1.begin(); it != v1.end(); it++)
			{
				//cout << *it << "\n";
				if (*it % D > 0)
				{
					int p1 = *it/D;
					cnt1+= p1;
					//cout << p1 << "\n";
				}
			}
			if (cnt1 >= m)
				printf ("YES\n");
			else
			{
				printf ("NO\n");
			}
		}
	}
	return 0;
}
