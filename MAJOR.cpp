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
		map<int,int> m1;
		map<int,int>::iterator it;
		int num;
		for (int i = 0; i < n; i++)
		{
			scanf ("%d",&num);
			m1[num]+= 1;
		}
		int valid = n/2;
		bool found = true;
		for (it = m1.begin(); it != m1.end(); it++)
		{
			if ((it->second) > valid)
			{
				//cout << it->first << "->" << it->second << "\n";
				printf ("YES %d\n",it->first);
				found = false;
				break;
			}
		}
		if (found)
			printf ("NO\n");

	}
	return 0;
}
