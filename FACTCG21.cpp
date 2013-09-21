#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 10000000
int primes[MAX+1];
void sieve()
{
	primes[1] = 1;
	for (long long int i = 2; i <= MAX; i++)
	{
		if (!primes[i])
		{
			primes[i] = i;
			for (long long int j = i; i*j <= MAX; j++)
			{
				if (!primes[j*i])
					primes[j*i] = i;
			}
		}

	}
}
int main()
{
	sieve();
	int N;
	while (scanf ("%d",&N) != EOF)
	{
		if (N == 1)
		{
			printf ("1\n");
			continue;
		}
		printf ("1");
		while (N > 1)
		{
			//cout << primes[N] << "\n";
			printf (" x %d",primes[N]);
			N/= primes[N];
		}
		printf ("\n");
	}
	return 0;
}
