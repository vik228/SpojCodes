#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define MAX 3000
#define MAX1 3000
int dp[3000][3000];
using namespace std;
int find_edit_distance (string A, string B)
{
	int a = A.length();
	int b = B.length();
	for (int i = 0; i <= a; i++)
	{
		for (int j = 0; j <= b; j++)
			dp[i][j] = 0;
	}
	for (int i = 1; i <= a; i++)
	{
		dp[i][0] = i;
	}
	for (int j = 1; j <= b; j++)
	{
		//cout << " hiii \n";
		dp[0][j] = j;
		//cout << dp[j][0] << "\n";
	}
	#ifdef DEBUG1
		for (int i = 0; i <= a; i++)
		{
			cout << "\n";
			for (int j = 0; j <=b; j++)
				cout << dp[i][j] << " ";
		}
	#endif
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j <= b; j++)
		{
			if (A[i - 1] != B[j - 1])
			{
				int p = min(dp[i - 1][j] + 1,dp[i][j - 1] + 1);
				if ( p < (dp[i - 1][j - 1] + 1))
					dp[i][j] = p;
				else
					dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				int q = min(dp[i - 1][j] + 1,dp[i][j - 1] + 1);
				if ( q < dp[i - 1][j - 1])
					dp[i][j] = q;
				else
					dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}
	#ifdef DEBUG
		for (int i = 0; i <= a; i++)
		{
			cout << "\n";
			for (int j = 0; j <= b; j++)
			{
				cout << dp[i][j] << " ";
			}
		}
		cout << "\n";
	#endif
	return dp[a][b];

}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		string A,B;
		cin >> A >> B;
		int ans = find_edit_distance (A,B);
		printf ("%d\n",ans);
	}
}

