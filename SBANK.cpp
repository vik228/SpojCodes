#include <iostream>
#include <cstdio>
#include <map>
#include <string.h>
using namespace std;
int main()
{
	int t;
	scanf ("%d",&t);
	int n;
	while (t--)
	{
		scanf ("%d",&n);
		char acc_no[50], s[50], out[50];
		map <string, int> m1;
		map <string, int>::iterator it;
		gets (s);
		for (int i = 0; i < n; i++)
		{
			//getline (cin, s);
			gets (acc_no);
			m1[acc_no] += 1;
		}
		for (it = m1.begin(); it != m1.end(); it++)
		{
			cout << it->first;
			printf (" %d\n",it->second);
		}
		printf ("\n");

	}
	return 0;
}
