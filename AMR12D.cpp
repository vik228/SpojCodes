#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		string s;
		cin >> s;
		int t = s.length();
		bool val1 = false;
		if (t%2 == 0)
		{
			int idx1 = t/2-1;
			int idx2 = t/2;
			for (int i = 0; i < t/2; i++)
			{
				if (s[idx1] != s[idx2])
				{
					printf ("NO\n");
					val1 = true;
					break;
				}
				idx2++;
				idx1--;
			}


		}
		else
		{
			int idx1 = t/2 -1;
			int idx2 = t/2+1;
			for (int i = 0; i < t/2; i++)
			{
				if (s[idx1] != s[idx2])
				{
					printf ("NO\n");
					val1 = true;
					break;
				}
				idx2++;
				idx1--;
			}
		}
		if (!val1)
			printf ("YES\n");
	}
	return 0;
}
