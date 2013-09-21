#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 1000050
int input[MAX];
int main()
{
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		int n;
		scanf ("%d",&n);
		for (int i = 0; i < n; i++)
			scanf ("%d",&input[i]);
		if (!next_permutation (input, input + n))
			printf ("-1\n");
		else
		{
			for (int i = 0; i < n; i++)
				printf ("%d",input[i]);

		}
		cout << "\n";
	
	}
	return 0;
}
