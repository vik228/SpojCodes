#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 10000007 
long long dp[110][110];
long long find_nCr (int n, int r)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= r and j <= i; j++)
		{
			if (j == 0 or j == i)
				dp[i][j] = 1;
			else
				dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MAX;
		}
	}
	return dp[n][r];

}
int main()
{
	int n,r;
	scanf ("%d%d",&n,&r);
	if (n == r)
	{
		printf ("1\n");
		//continue;
	}
	else if (n < r)
	{
		printf ("-1\n");
		//continue;
	}
	else
	{

		printf ("%d\n",find_nCr (n-1,r-1));

	}
	return 0;
}

