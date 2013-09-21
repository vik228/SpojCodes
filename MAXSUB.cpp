#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
int input[50001];
#define MOD 1000000009
using namespace std;

int power(int x, int pow) 
{
	if(pow==0)
		return 1;

	if(pow==1)
		return x;
	if(pow==2)
		return ((long long) x*x)%MOD;

	int z = power(x, pow/2);
		z = power(z,2);

	if(pow%2==1) 
	{
		z = ((long long) z*x)%MOD;
	}
	return z;
}
int main()
{
	int t;
	int* ar_ptr;
	ar_ptr=input;
	scanf("%d",&t);
	while(t--)
	{
		int n,it=0,cnt0=0;
		long long sum=0,maxsum,count;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&input[i]);
			it++;
			if(input[i]==0)
				cnt0++;
			//cout<<cnt0<<"\n";
		}
		sort(ar_ptr,ar_ptr+it);
		maxsum=input[it-1];
		for(int j=it-1;j>=0;j--)
		{
			sum+=input[j];
			//cout<<sum<<"\n";
			if(sum>maxsum)
			{
				maxsum=sum;
			}
			else
				continue;
		}
		cout<<maxsum<<" ";
		if(maxsum==0)
		{
			int cnt=power(2,cnt0)-1;
			//cout<<cnt0;
			cout<<cnt<<"\n";
			continue;
		}
		if(maxsum<0)
		{
			int v=0;
			for(int i=it-1;i>=0;i--)
			{
				//cout<<maxsum<<"\n"<<input[i]<<"\n";
				if(input[i]==maxsum)
				{
				//	cout<<"hiii";
					v++;
				}
				else
					break;
			}
			cout<<v<<"\n";
			continue;
		}
		if(maxsum>0)
		{
			int cnt = power(2,cnt0);
			cout<<cnt<<"\n";
			continue;
		}


	}
	return 0;
}
