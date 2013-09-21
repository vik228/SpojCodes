#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
char input[300];
int numbers[300];
int dp[300][300];
char operators[300];
#define DEBUG
using namespace std;
int main()
{
	int k;
	scanf ("%d",&k);
	while (k--)
	{
		scanf ("%s",input);
		int n = strlen(input);
		int t = 0,o = 0;
		for (int i = 0; i < n; i++)
		{
			if (isdigit(input[i]))
				numbers[t++] = input[i] - '0';
			else
				operators[o++] = input[i];
		}
		for (int i = 0; i < t; i++)
			dp[i][i] = numbers[i];
		#ifdef DEBUG
			for (int i = 0; i < t; i++)
			{
				cout << "\n";
				for (int j = 0; j < t; j++)
					cout << dp[i][j] << " ";

			}
			cout << "\n";
		#endif
		for (int l = 2; l <= t; l++)
		{
			for (int i = 0; i <= n-l; i++)
			{
				int j = i + l - 1;
				dp[i][j] = 0;
				for (int p = i; p < j; p++)
				{
					if (operators[p] == '+')
						dp[i][j] = max (dp[i][j],dp[i][p] + dp[p + 1][j]);
					else
						dp[i][j] = max (dp[i][j],dp[i][p] * dp[p + 1][j]);
				}


			}
		}
		printf ("%d ",dp[0][t- 1]);
		
		for (int l = 2; l <= t; l++)
		{
			for (int i = 0; i <= n-l; i++)
			{
				int j = i + l - 1;
				dp[i][j] = 1000000000;
				for (int p = i; p < j; p++)
				{
					if (operators[p] == '+')
						dp[i][j] = min (dp[i][j],dp[i][p] + dp[p + 1][j]);
					else
						dp[i][j] = min (dp[i][j],dp[i][p] * dp[p + 1][j]);
				}


			}
		}
		printf ("%d\n",dp[0][t- 1]);



	}
	return 0;
}


