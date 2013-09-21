#include <iostream>
#include <cstdio>
int ip[100010];
using namespace std;
int main()
{
	int n;
	while (scanf ("%d",&n))
	{
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++)
			scanf ("%d",&ip[i]);
		bool ab = true;
		for (int i = 1; i <= n; i++)
		{
			if (ip[ip[i]] != i)
			{
				ab = false;
				
			}
		}
		if (ab)
			printf ("ambiguous\n");
		else
			printf ("not ambiguous\n");



	}
	return 0;
}

