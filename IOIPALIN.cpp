#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 6110
int dp[2][MAX];
using namespace std;
int main()
{
	int N;
	scanf ("%d",&N);
	string s;
	cin >> s;
	string s_rev = s;
	int ans = 0;
	for (int i = 0; i < 2; i++)
		dp[i][0] = 0;
	for (int j = 0; j <= N; j++)
		dp[0][j] = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (s[i-1] == s_rev[N-j])
			{
				dp[i&1][j] = dp[1-(i&1)][j-1]+1;
					//ans = max (dp[i&1][j], ans);
			}
			else
				dp[i&1][j] = max (dp[1-(i&1)][j], dp[i&1][j-1]);
		}
	}
	printf ("%d\n",(N-dp[N&1][N]));
	return 0;

}


