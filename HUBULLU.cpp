#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		int n,s;
		scanf ("%d%d",&n,&s);
		if (s == 1)
			printf ("Pagfloyd wins.\n");
		else
			printf ("Airborne wins.\n");
	}
	return 0;
}
