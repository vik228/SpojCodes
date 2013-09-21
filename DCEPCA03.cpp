#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define MAX2 1900
#define MAX 1 << 14
unsigned A[MAX>>6];
int primes[MAX2];
#define chk(n) (A[(n)>>6]&(1<<(((n)>>1)&31)))
#define set(n) (A[(n)>>6]|=(1<<(((n)>>1)&31)))
int phi[10050];
using namespace std;
void sieve()
{
    for (unsigned i = 3; i*i <= MAX; i+= 2)
    {
        int v = chk(i);
        if (v == 0)
		for (unsigned j = i*i,k=i<<1; j < MAX; j+=k)
		{
			set(j);
		}
    }
    int q = 1;
    primes[0] = 2;
    for (unsigned i = 3; i < MAX; i+=2)
    {
        int v = chk(i);
        if (v == 0)
            primes[q++] = i;
    }
}
int pow (int n, int i)
{
	if (i == 0)
		return 1;
	else
		return (n*pow(n, i-1));
}
int eular_phi_function (int n)
{
	if (binary_search (primes, primes+MAX2, n))
		return (n-1);
	int ret_val = 1;
	for (int i = 0; primes[i]*primes[i] <= n; i++)
	{
		int cnt = 0;
		if (n%primes[i] == 0)
		{
			while (n%primes[i] == 0)
			{
				cnt++;
				n/= primes[i];

			}
			if (cnt > 0)
			{
				ret_val*= (pow (primes[i], cnt-1)*(primes[i]-1));	
			}
		}
	}
	if (n != 1)
		ret_val*= n-1;
	return ret_val;
}
int main()
{
	sieve();
	int T;
	long long sum = 0;
	for (int i = 1; i <= 10000; i++)
	{
		phi[i] = eular_phi_function (i);
	}

	scanf ("%d",&T);
	while (T--)
	{
		int N;
		scanf ("%d",&N);
		long long H = 0;
		for (int i = 1; i <= N; i++)
		{
			H+= phi[i];
		}
		printf ("%lld\n",H*H);

	}
	return 0;
}
