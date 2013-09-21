#include<iostream>
#include<cstdio>
using namespace std;
long long merge(int A[],int start,int mid,int end,int tmp[])
{
	int i,j,k;
	i=start;
	k=start;
	j=mid+1;
	long long count=0;
	for(int p = i; p <= mid; p++)
	{
		while(j <= end)
		{
			if(A[p] > A[j])
			{
				j++;
			}
			else
				break;
		}
		count+=j-(mid+1);
	}
	j=mid+1;
	while(i<=mid and j<=end)
	{
		if(A[i]<=A[j])
			tmp[k++]=A[i++];
		else
			tmp[k++]=A[j++];
	}
	while(i<=mid)
		tmp[k++]=A[i++];
	while(j<=end)
		tmp[k++]=A[j++];
	for(int t=start;t<=end;t++)
		A[t]=tmp[t];
	return count;
}
long long mergeSort(int A[],int i,int j,int tmp[])
{
	if(i>=j)
		return 0;
	int mid=(i+j)/2;
	long long lc=mergeSort(A,i,mid,tmp);
	long long rc=mergeSort(A,mid+1,j,tmp);
	long long mc=merge(A,i,mid,j,tmp);
	return lc+rc+mc;
}

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int arr[n],tmp[n];
		long long ans;
		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		ans =  mergeSort(arr,0,n-1,tmp);
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<"\n";
		printf("%lld\n",ans);
		
	}
}
