#include <iostream>
#include <cstdio>
using namespace std;
int find_n(int n)
{
	if (n%2 == 0)
		return n/2;
	else
		return n/2+1;
}
int find_max(int n,int q)
{
	if (n == 3)
		return 3 - q;
	else
	{
		if (q == 0)
			q = 1;
		else if (q == 1)
		{
			if (n%2 == 0)
				q = 1;
			else
				q = 2;
		}
		else
			q = 2;
		return (find_max(find_n(n) + 1,q) + 1);
	}
}
int main()
{
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		int n;
		scanf ("%d",&n);
		printf ("%d\n",find_max(n,0));
	}
	return 0;
}
