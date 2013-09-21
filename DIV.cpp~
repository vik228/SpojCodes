#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
using namespace std;
//#define DEBUG
#define MAX 1000000
#define LMT 1000
#define MAX2 78499
unsigned flag[MAX>>6];
int primes[MAX2];
#define ifc(n) (flag[(n)>>6]&(1<<(((n)>>1)&31)))
#define isc(n) (flag[(n)>>6]|=(1<<(((n)>>1)&31)))
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
int divisor_count(int n)
{	
	int div_count = 1;
	for (int i = 0; primes[i]*primes[i] <= n; i++)
	{
		if(n%primes[i] == 0)
		{
			int pow = 0;
			while(n%primes[i] == 0)
			{
				pow++;
				n/=primes[i];

			}
			div_count*= (pow+1);
		}
		
	}
	if(n!=1)
		div_count*=2;
	return div_count;
}
int main()
{
	sieve();
	#ifdef DEBUG
		for (int i = 0 ; i < 78499; i++)
			cout << primes[i] << "\n";
	#endif
	int num_count = 0;
	for (int i = 12; i <= MAX; i++)
	{
		int cnt = divisor_count(i);
		//cout << i << ":" << cnt << "\n";
		for (int k = 0; primes[k]*primes[k] <= cnt; k++)
		{
			if(cnt%primes[k] == 0)
			{
				int p = cnt/primes[k];
				if(binary_search(primes, primes + MAX2, p) and p != primes[k])
				{
					num_count++;
				}
				break;
			}
		}
		//cout << num_count << "\n";
		if(num_count == 9)
		{
			printf("%d\n",i);
			num_count = 0;
		}

	}
	
	return 0;
}

