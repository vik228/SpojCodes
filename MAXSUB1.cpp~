#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
int input[50001];
#define MOD 1000000009
using namespace std;

int power(int x,int pow)
{
	if(pow==0)
		return 1;
	else
		return (x*power(x,pow-1))%MOD;
}
int main()
{
	int t;
	int* ar_ptr;
	ar_ptr=input;
	scanf("%d",&t);
	while(t--)
	{
		int n,it=0;
		long long sum=0,maxsum,count;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&input[i]);
			it++;
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
		if(binary_search(ar_ptr,ar_ptr+it,maxsum))
		{
			int count_maxsum=0;
			int* low = lower_bound(ar_ptr,ar_ptr+it,maxsum);
			int index = low-ar_ptr;
			while(input[index]==maxsum and index!=it)
			{
				count_maxsum++;
				index++;
			}
			if(maxsum==0)
				count=power(2,count_maxsum)-1;
			else if(binary_search(ar_ptr,ar_ptr+it,0))
			{
				int count_0=0;
				int* low = lower_bound(ar_ptr,ar_ptr+it,0);
				int index = low - ar_ptr;
				//cout<<index<<"\n";
				while(input[index]==0 and index!=it)
				{
					//cout<<"hiii\n";
					count_0++;
					index++;
				}
				count = power(2,count_0);
			}
			else
				count=count_maxsum;
		}
		else if(binary_search(ar_ptr,ar_ptr+it,0))
		{
			int count_0=0;
			int* low = lower_bound(ar_ptr,ar_ptr+it,0);
			int index = low - ar_ptr;
			while(input[index]==0 and index!=it)
			{
				count_0++;
				index++;
			}
			count =power(2,count_0);
				
		}
		else
			count=1;
		cout<<maxsum<<" "<<count<<"\n";


	}
	return 0;
}


