#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#define MAX 100010
using namespace std;
int main()
{
	long t,at,bt;
	scanf("%ld", &t );
	int arr[MAX];
	while(t--)
	{
		long maxlen=0,maxval=0,sum=0,p,q;
		scanf("%ld%ld", &at, &bt );
	
		//arr=new int[at+1];
		for(long i=1;i<=at;i++)
		 scanf("%ld", &arr[i] );
		q=1;
		for(p=1;p<=at;p++)
		{
			sum+=arr[p];
			if(sum<=bt)
			{
				if( p - q + 1 > maxlen )
				{
					maxval=sum;
					maxlen=p - q + 1;
				}
				else if( p - q + 1 == maxlen )maxval = min( maxval, sum );
			}
			else
			{
				sum-=arr[q];
				q++;
				if(sum <= bt)
				{
					 if( p - q + 1 == maxlen )maxval = min( maxval, sum );
				}
				
			}
		}
		printf("%ld %ld\n", maxval, maxlen);
	}
	return 0;
}
				









