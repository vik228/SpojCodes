#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define MAX 1000001
#define PRIMES 78498
int flags[MAX];
int primes[PRIMES];
using namespace std;
void sieve()
{
	memset(flags,0,sizeof(flags));
	flags[0] = flags[1] = 1;
	for (int i = 2; i*i <= MAX ; i++)
	{
		for (int j = i+i; j < MAX; j+= i)
		{
			flags[j] = 1;
		}
	}
	int k = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (flags[i] == 0)
			primes[k++] = i;
	}
}
int main()
{
	sieve();
	/*
	for (int i = 0; i < PRIMES; i++)
		cout << primes[i] << "\n";
	exit(0);
	*/
	int c;
	scanf ("%d",&c);
	while (c--)
	{
		long long N;
		scanf ("%lld",&N);
		bool is_multiple = true;
		for (int i = 0; 1LL*primes[i]*primes[i] <= N; i++)
		{
			int count = 0;
			while (N % primes[i] == 0)
			{
				count++;
				N/= primes[i];
				//cout << primes[i];
			}
			if (primes[i]%4 == 3 and count%2 == 1)
			{
				is_multiple = false;
				break;
			}
		}
		if (N%4 == 3)
			is_multiple = false;
		if(is_multiple)
			printf("Yes\n");
		else
			printf ("No\n");

	}
	return 0;
}



