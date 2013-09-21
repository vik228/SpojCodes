#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 6110
int dp[2][MAX];
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		string s;
		cin >> s;
		int l1 = s.length();
		string s_rev = s;
		int l2 = s_rev.length();
		int ans = 0;
		for (int i = 0; i < 2; i++)
			dp[i][0] = 0;
		for (int j = 0; j <= l2; j++)
			dp[0][j] = 0;
		for (int i = 1; i <= l1; i++)
		{
			for (int j = 1; j <= l2; j++)
			{
				if (s[i-1] == s_rev[l2-j])
				{
					dp[i&1][j] = dp[1-(i&1)][j-1]+1;
					//ans = max (dp[i&1][j], ans);
				}
				else
					dp[i&1][j] = max (dp[1-(i&1)][j], dp[i&1][j-1]);
			}
		}
		printf ("%d\n",(l1-dp[l2&1][l2]));
	}

}
