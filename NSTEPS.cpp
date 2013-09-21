#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int x,y;
		scanf ("%d%d",&x,&y);
		if (x == y)
		{
			if (x % 2 == 0)
				printf ("%d\n",2*x);
			else
				printf ("%d\n",2*x - 1);

		}
		else if ((x - y) == 2)
		{
			if (x%2==0 and y%2==0)
			{
				printf ("%d\n",x+y);
			}
			else if (x%2 == 1 and y%2 == 1)
				printf ("%d\n",x+y-1);
		}
		else
			printf ("No Number\n");
	}
	return 0;
}
