#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf ("%d",&n);
	while (1)
	{
		if (n == 0)
			break;
		else
		{
			int ans = (n*(n+1)*(2*n + 1))/6;
			printf ("%d\n",ans);
			scanf ("%d",&n);
		}
	}
	return 0;
}
