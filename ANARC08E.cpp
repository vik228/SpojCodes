#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a,b;
	while( scanf ("%d %d",&a,&b))
	{
		if (a == -1 and b == -1)
			break;
		else if (a == 1 or b == 1)
			printf ("%d+%d=%d\n",a,b,a+b);
		else
			printf ("%d+%d!=%d\n",a,b,a+b);
	}
		return 0;
		
}
