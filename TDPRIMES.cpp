#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>

#define MAX 100000000
#define LMT 10000
#define MAX2 5761551


unsigned flag[MAX>>6];
int primes[MAX2];

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
	return q;
}
int main()
{
	int ret_value;
	ret_value=sieve();
	for(int i=0;i<ret_value;i++)
	{
		if((i+1)%100==1)
			cout<<primes[i]<<"\n";
	}
	return 0;
}
