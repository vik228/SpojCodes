#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector <int> input;
long long findMin (int a, int b)
{
	long long min_val = a + b;
	for (int i = 1; i < input.size(); i++)
	{
		int num_days = input[i] - input[i-1];
		long long v1 = num_days*b;
		long long v2 = 2*a + b;
		min_val += min (v1, v2);
	}
	min_val += a;
	return min_val;
}
int main()
{
	int T;
	scanf ("%d",&T);
	int cse = 0;
	while (T--)
	{
		cse++;
		input.clear();
		int n, a, b;
		scanf ("%d %d %d",&n, &a, &b);
		for (int i = 0; i < n; i++)
		{
			int val;
			scanf ("%d",&val);
			input.push_back (val);
		}
		printf ("Case #%d: %lld\n", cse, findMin (a, b));
	}
	return 0;
}
