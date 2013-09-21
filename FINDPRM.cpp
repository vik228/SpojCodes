#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#define MAX2 664579
#define MAX 10000000
unsigned A[MAX>>6];
int primes[MAX2];
#define chk(n) (A[(n)>>6]&(1<<(((n)>>1)&31)))
#define set(n) (A[(n)>>6]|=(1<<(((n)>>1)&31)))
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
int main()
{
	sieve();
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int N;
		scanf ("%d",&N);
		int idx;
		int *p = lower_bound (primes, primes+MAX2, N/2);
        //exit(0);
		idx = p - primes;
		if (binary_search (primes, primes + MAX2, N/2))
		{
				idx+= 1;
		}
		int* pt = lower_bound (primes + idx, primes + MAX2, N);
        int idx1 = pt - primes;
        int cnt;
        if (binary_search (primes, primes + MAX2, N))
             cnt = idx1 - idx + 1;
        else
            cnt = idx1 - idx;
		printf ("%d\n",cnt);
	}
	return 0;
	
	
}

