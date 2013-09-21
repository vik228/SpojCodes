#include<iostream>
#include<cstdio>
#include<cstdlib>
int cost[300001];
using namespace std;
int main()
{
	long long n,m,sum=0,maxval=0;
	long long p=0,q=0;
	cin>>n>>m;
	for(long long i=0;i<n;i++)
		cin>>cost[i];
	for(int i=0;i<n;i++)
	{
		sum+=cost[i];
		if(sum<m && sum>maxval)
		{
			maxval=sum;
			q++;
		}
		else if(sum==m)
		{
			maxval=sum;
			cout<<maxval;
			break;
		}
		else if(sum>m)
		{
			while(sum>m)
			{
				sum-=cost[p];
				p++;
			}
			if(sum>maxval)
				maxval=sum;
		}
	}
	cout<<maxval;
	return 0;
}

			

