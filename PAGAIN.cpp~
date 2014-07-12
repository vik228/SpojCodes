#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 65536
unsigned flag[MAX>>6];
unsigned primes[6600];
unsigned primelen;
#define ifc(n) (flag[(n)>>6]&(1<<(((n)>>1)&31)))
#define isc(n) (flag[(n)>>6]|=(1<<(((n)>>1)&31)))
using namespace std;
int sieve()
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
	primelen = q;
	return q;
}
bool isPrime(unsigned n)
{
	for (int i = 0; i < primelen && primes[i]*primes[i] <= n; i++)
	{
		if (n%(primes[i]) == 0)
			return false;
	}
	return true;
}
int main()
{
	int T;
	sieve();
	scanf ("%d",&T);
	while (T--)
	{
		unsigned long long N;
		scanf ("%llu",&N);
		if (N < 5)
		{
			printf ("2\n");
			continue;
		}
		if( N > 4294967291LL )
		{
			printf("4294967291\n");
			continue;
		}
		if (N & 1)
			N-= 2;
		else
			N-= 1;
		unsigned n = unsigned(N);
		if (N < MAX)
		{
			for (; ;n-= 2)
			{
				if (!ifc(n))
				{
					printf ("%u\n",n);
					break;
				}
			}
		}
		else
		{
			for (; ; n-= 2)
			{
				if (isPrime(n))
				{
					printf ("%u\n",n);
					break;
				}
			}
		}
	}
	return 0;
}
