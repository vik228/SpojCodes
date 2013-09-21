#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int lcs[1010][1010];
int LCS (string s1, string s2)
{
	int m = s1.length();
	int n = s2.length();
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (s1[i-1] == s2[j-1])
			{
				lcs[i][j] = 1 + lcs[i-1][j-1];
			}
			else
				lcs[i][j] = max (lcs[i-1][j], lcs[i][j-1]);
		}
	}
	return lcs[m][n];
}
int main()
{
	string S, T;
	while (cin >> S >> T)
	{
		if (S == "#" or T == "#")
			break;
		int lcs = LCS (S, T);
		int ans = 15* (S.length() - lcs) + 30*(T.length() - lcs);
		printf ("%d\n", ans);
	}
	return 0;
}
