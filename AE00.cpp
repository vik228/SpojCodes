#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	scanf ("%d",&n);
	int num_rect = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; i*j <= n; j++)
		{
			if (i <= j)
				num_rect++;
		}
	}
	printf ("%d\n",num_rect);
	return 0;

}	

