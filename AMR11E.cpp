#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 10000
int flags[MAX];
int primes[2000];
int distinct_primes[MAX];
using namespace std;
void sieve()
{
	memset (flags,0,sizeof(flags));
	flags[0] = flags[1] = 1;
	for (int i = 2; i*i <= MAX; i++)
	{
		for (int j = i + i; j < MAX; j+= i)
			flags[j] = 1;
	}
	int k = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (flags[i] == 0)
		{
			primes[k++] = i;	
		}
	}
}
void generate_lucky_numbers()
{
	int k = 1;
	for (int i = 30; k <= 1000; i++)
	{
		int cnt = 0;
		for (int j = 0; primes[j] <= i/2; j++)
		{
			if (i%primes[j] == 0)
			{
				//cout << primes[j] << "\n";
				cnt++;
				if (cnt == 3)
				{
					distinct_primes[k++] = i;
					break;
				}
			}
		}
		//cout << cnt << "\n";
	}
}
int main()
{
	sieve();
	generate_lucky_numbers();
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		int n;
		scanf ("%d",&n);
		printf ("%d\n",distinct_primes[n]);
	}
	return 0;
}
