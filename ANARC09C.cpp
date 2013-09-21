#include<iostream>
#include<math.h>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
using namespace std;
int primes[80000];
int arr3[80000],arr4[80000];
void generate_primes()
{
	int a[1000001] = {0};
	a[0]=a[1]=1;
	for(int i=2;i*i<=10000001;i++)
	{
		if(a[i]==0)
			for(int j=i+i;j<=1000000;j+=i)
				a[j]=1;
	}
	for(int i=2,c=0;i<1000001;i++)
	{
		
		if(a[i]==0)
		{
			//cout<<i<<"\n";
			primes[c++]=i;
		}
	}
		
}
int main()
{
	int n1,b,n2,c,t1,t2;
	int p=0;
	generate_primes();
	//exit(0);
	while(cin>>n1>>n2)
	{
		if(n1==0 && n2==0)
			exit(0);
		t1 = n1;
		t2 = n2;
		memset(arr3,0,sizeof(arr3));
		memset(arr4,0,sizeof(arr4));
		p++;
		set<int>s1;
		for(int i=0;primes[i]<=n1 && t1 != 1;i++)
		{
				int lpcounter=0;
				while((t1%primes[i])==0)
				{
					t1=t1/primes[i];
					lpcounter++;
				}
			if(lpcounter>0)
			{
				arr3[i]=lpcounter;
				s1.insert(i);
				
			}		
					
					
				
		}
		for(int i=0;primes[i]<=n2 && t2!=1;i++)
		{
				int lpcounter=0;
				while((t2%primes[i])==0)
				{
					t2=t2/primes[i];
					lpcounter++;
				}
			if(lpcounter>0)
			{
				arr4[i]=lpcounter;
				//printf("%d %d\n", primes[i], lpcounter);
				s1.insert(i);
			}		
					
					
				
		}
		long ans = 0;
		for(set< int >::iterator i=s1.begin();i!=s1.end();i++)
		{
		 ans += abs( arr4[*i] - arr3[*i] );
		 //printf("%d\n", primes[*i] );
		}
		printf("%d. %d:%ld\n",p, s1.size(), ans );
			
			
		


	}
	return 0;
}
	
