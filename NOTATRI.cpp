#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==0)
			break;
		int a[n];
		int* ptr;
		ptr=a;
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(ptr,ptr+n);
		int count=0;
		for(int i=0;i<n;i++)
		{
			int sum=a[i];
			for(int j=i+1;j<n;j++)
			{
				sum+=a[j];
				int* low = lower_bound(ptr,ptr+n,sum+1);
				int index = low - ptr;
				count+=n-index;
				sum=a[i];
					
				
			}
		}
		cout<<count<<"\n";
	}
		return 0;

}
