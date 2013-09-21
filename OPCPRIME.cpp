#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>

#define MAX 1000000
#define LMT 1000
#define MAX2 78498



unsigned flag[MAX>>6];
int primes[MAX2];

#define ifc(n) (flag[(n)>>6]&(1<<(((n)>>1)&31)))
#define isc(n) (flag[(n)>>6]|=(1<<(((n)>>1)&31)))
using namespace std;
void sieve()
{
	unsigned i,j,k,q;
	for(i=3;i*i<MAX;i+=2)
	{
	        int v = ifc(i);
	        if(v==0)
			for(j=i*i,k=i<<1;j<MAX;j+=k)
			{
			      
				isc(j);
			}
		
	}
	primes[0]=2;
	for(i=3,q=1;i<MAX;i+=2)
	{
		int v = ifc(i);
		if(v==0)
		{
			
		       // cout<<i<<"\n";
			primes[q++]=i;
		}
	}
}
int main()
{
	sieve();
	long long n;
	scanf ("%lld",&n);
	if (n == 1)
		printf ("1\n");
	else
	{
		for (int i = 0; 1LL*primes[i]*primes[i] <= n; i++)
		{
			if (n % (primes[i]) == 0)
			{
				printf ("%d\n",primes[i]);
				while (n % primes[i] == 0)
				{
					n/= primes[i];

				}
			}
		}
		if (n > 1)
			printf ("%lld\n",n);
	}
	
	return 0;
}

