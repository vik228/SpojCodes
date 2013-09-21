#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int a[4000],b[4000],c[4000],d[4000];
int lhs[16000001],rhs[16000001];
int main()
{
	int n;
	int* lhs_ptr;
	int* rhs_ptr;
	lhs_ptr=lhs;
	rhs_ptr=rhs;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	int it1=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			lhs[it1]=a[i]+b[j];
			rhs[it1++]=-(c[i]+d[j]);
		}
	}
	sort(lhs_ptr,lhs_ptr+it1);
	sort(rhs_ptr,rhs_ptr+it1);
	int ans=0;
	pair<int*,int*> pi;
	for(int i=0;i<it1;i++)
	{
		int val=lhs[i];
		/*
		int* low = lower_bound(rhs_ptr,rhs_ptr+it1,val);
		int index_low = low - rhs_ptr;
		int* high = upper_bound(rhs_ptr,rhs_ptr+it1,val);
		int index_high = high - rhs_ptr;
		ans+=index_high-index_low;
		*/
		pi=equal_range(rhs_ptr,rhs_ptr+it1,val);
		ans+=(pi.second-rhs_ptr)-(pi.first-rhs_ptr);
		
	
	}
	printf("%d\n",ans);

	return 0;
}


