#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 100000
int input[MAX];
int main()
{
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		int n,p;
		scanf ("%d%d",&n,&p);
		for (int i = 0; i < n; i++)
			scanf ("%d",&input[i]);
		sort (input, input+n);
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (binary_search (input, input+n, p-input[i]))
				cnt++;
		}
		printf ("%d\n",cnt/2);

	}
}
