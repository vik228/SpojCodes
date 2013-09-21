#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define MAX 1000000
#define MAXRTN 78498
//#define DEBUG
int flag[MAX>>6];
int primes[MAXRTN];
#define ifc(n) (flag[(n)>>6]&(1<<(((n)>>1)&31)))
#define isc(n) (flag[(n)>>6]|=(1<<(((n)>>1)&31)))
using namespace std;
int generate_primes()
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
	int t;
	generate_primes();
	#ifdef DEBUG
		for (int i = 0; i < MAXRTN; i++)
		{
			cout << primes[i] << "\n";
		}
	#endif
	//exit(0);
	scanf ("%d",&t);
	while (t--)
	{
		int n;
		scanf ("%d",&n);
		if (n == 1)
		{
			printf ("1\n");
			continue;
		}
		int* ptr = lower_bound (primes,primes + MAXRTN,n);
		int idx = ptr - primes;
		//cout << idx << "\n";
		//cout << primes[idx] << "\n";
		if (primes[idx] == n)
		{
			printf ("%d\n",primes[idx] - 1);
		}
		else
		{
			int t1 = n;
			double ans = n;
			int i;
			for (i = 0; primes[i]*primes[i] <= t1; i++)
			{
				int cnt = 0;
				while (t1 % primes[i] == 0)
				{
					t1/= primes[i];
					cnt++;
				}
				if (cnt > 0)
					ans*= (1.0 - 1.0/primes[i]);
				if (t1 == 1)
					break;
			}
			if (t1 != 1)
				ans*= (1.0 - 1.0/t1);
			printf ("%d\n",(int)ceil(ans));
		}
	}
	return 0;
	
}
