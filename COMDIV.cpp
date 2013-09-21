#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAX 1000000
#define MAX2 78500
int flags[MAX];
int primes[MAX2];
using namespace std;
int gcd (int a,int b)
{
	if (b == 0)
		return a;
	else
		return gcd (b,a%b);
}
void sieve()
{
	memset (flags,0,sizeof(flags));
	memset (primes,0,sizeof(primes));
	flags[0] = flags[1] = 1;
	for (int i = 2; i*i <= MAX; i++)
	{
		for (int j = i+i; j < MAX; j+= i)
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
int main()
{
	sieve();
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int A,B;
		scanf ("%d%d",&A,&B);
		int g = gcd(A,B);
		//cout << g << "\n";
		int cnt = 1;
		for (int i = 0; primes[i]*primes[i] <= g; i++)
		{
			int pow = 0;
			if (g%primes[i] == 0)
			{
				while (g%primes[i] == 0)
				{
					pow++;
					g/= primes[i];
				}
				cnt*= pow+1;
			}

		}
		if (g != 1)
			cnt*= 2;
		printf ("%d\n",cnt);

	}
	return 0;
}


