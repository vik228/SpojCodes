#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<cstdio>

#define MAX 100000000
#define LMT 10000
#define MAX2 5761554


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
	int x,p;
	int *it;
	p=sieve();
	//cout<<p<<"\n";
	//exit(0);
	it=primes;
	while(cin>>x)
	{
		if(x==0)
			break;
		else
		{
			float error;
			float count1;
			int *count;
			count=lower_bound(it,it+p,x);
			float index=count-it;
			//cout<<index;
			//exit(0);
			float b=log(x);
			//cout<<x<<"\n"<<b;
			//exit(0);
			count1=x/b;
			//cout<<count1<<"\n";
			//exit(0);
			float diff;
			if(binary_search(it,it+p,x))
			{
				diff=abs((index+1)-count1);
				error=(diff/(index+1))*100;
			}
			else
			{
				//cout<<count1;
				//exit(0);
				diff=abs(index-count1);
				error=(diff/index)*100;
			}
			//cout<<error<<"\n";
			printf("%0.1f\n",error);
		}
	}
	return 0;
}

	


