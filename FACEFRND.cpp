#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
int N[101];
int main()
{
	int t;
	scanf ("%d",&t);
	set < int > s1;
	int M;
	for (int i = 0; i < t; i++)
	{
		scanf ("%d",&N[i]);
		cin >> M;
		int fof;
		while (M--)
		{
			scanf ("%d",&fof);
			s1.insert(fof);
		}

	}
	for (int i = 0; i < t; i++)
	{
		if (s1.find(N[i]) != s1.end())
			s1.erase(N[i]);
	}
	printf ("%d\n",s1.size());


}
