#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
int cost[1000010];
int ret_max (string s, int n)
{
	int cnt[26] = {0};
	cnt['G' - 'A'] = 1;
	cnt['R' - 'A'] = 2;
	cnt['Y' - 'A'] = 3;
	cnt['B' - 'A'] = 4;
	cnt['O' - 'A'] = 5;
	for (int i = 1; i < s.length(); i++)
	{
		cost[i] = abs ((cnt[s[i-1] - 'A']) - (cnt[s[i] - 'A']));
	}
	int max_val, max_sum = 0;
	int j = 0;
	int i;
	for (i = 1; i < s.length();)
	{
		if ((n - cost[i]) >= 0)
		{
			//cout << n << "-" << cost[i] << "\n";
			n -= cost[i];
			i++;
		}
		else
		{
			max_val = (i-j);
			max_sum = max (max_val, max_sum);
			while (n-cost[i] < 0 and j <= i)
			{
				//cout << n << "+" << cost[j+1] << "\n";
				n += cost[j + 1];
				j++;
			}
			if (i == j)
			{
				n -= cost[j];
				i++;
			}
		}

	}
	return max (max_sum, (i - j));


}
int main()
{
	int T;
	scanf ("%d",&T);
	int cse = 0;
	while (T--)
	{
		cse++;
		memset (cost, 0, sizeof(cost));
		int n;
		scanf ("%d",&n);
		string s;
		cin >> s;
		printf ("Scenario #%d: %d\n",cse, ret_max (s, n));
	}
	return 0;
}
