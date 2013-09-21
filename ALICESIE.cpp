#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int n;
		scanf ("%d",&n);
		if (n%2 == 0)
		{
			printf ("%d\n",n/2);
		}
		else
			printf ("%d\n",n/2+1);

	}
	return 0;

}
