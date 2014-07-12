#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 1200
int f[MAX];
vector <int> primes;
int phycoNumbers[1000];
bool isPhycoNum[1150];
void sieve ()
{
	f[0] = f[1] = 1;
	for (int i = 2; i*i < MAX; i++)
	{
		if (f[i] == 0)
		{
			for (int j = i; i*j < MAX; j++)
			{
				f[i*j] = 1;
			
			}
		}
	}
	for (int i = 0; i < MAX; i++)
	{
		if (f[i] == 0)
			primes.push_back (i);
	}
}
bool isSubsetSum (int N, int sum)
{
	int possiblesum[sum+1];
	memset (possiblesum, 0, sizeof (possiblesum));
	possiblesum[0] = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = sum; j >= phycoNumbers[i]; j--)
		{
			if (possiblesum[j-phycoNumbers[i]] == 1)
				possiblesum[j] = 1;
		}
	}
	return (possiblesum[sum] == 1);
}
void findPhycoNumbers ()
{
	for (int val = 1; val <= 1100; val++)
	{
		int num = val;
		int cnt_even = 0, cnt_odd = 0;
		if (f[val] == 0)
			continue;
		for (int i = 0; primes[i]*primes[i] <= num; i++)
		{
			int cnt = 0;
			while (num%primes[i] == 0)
			{
				cnt++;
				num /= primes[i];
			}
			if (cnt%2 == 0 and cnt != 0)
				cnt_even += 1;
			else if (cnt != 0)
				cnt_odd += 1;
		}
		if (num != 1)
			cnt_odd++;
		if (cnt_even > cnt_odd)
			isPhycoNum[val] = true;
	}
	

}
int main() 
{
	int T;
	sieve();
	findPhycoNumbers ();
	scanf ("%d",&T);
	while (T--)
	{
		int N, K;
		scanf ("%d%d",&N,&K);
		int val;
		int sum = 0;
		int k = 0;
		for (int i = 0; i < N; i++)
		{
			scanf ("%d",&val);
			if (isPhycoNum[val])
			{
				phycoNumbers[k++] = val;
				sum += val;
			}
		}
		if (k > sum)
			printf ("No\n");
		else if (isSubsetSum (k, K))
			printf ("Yes\n");
		else
			cout << "No\n";
	}
	return 0;
}

