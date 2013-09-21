#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int t,at;
	long bt;
	int *arr;
	int array[100];

	cin>>t;
	while(t--)
	{
		cin>>at>>bt;
		arr=new int[at+1];
		for(int i=1;i<=at;i++)
			cin>>arr[i];
		long sum=0;
		int k;
		for(int j=1;j<=at;j++)
		{
			k=j;
			sum=0;
			while(sum<bt)
			{
				if((sum+arr[k])>=bt)
					break;
				else
				{
					sum+=arr[k];
				}
				k++;
			}
				array[k-j]=sum;

		}
		for(int i=0;i<100;i++)
		{
			if(!array[i])
				array[i]=0;
			continue;
		}
		int p=1;
		while(array[p])
		{
			if(!array[p+1])
				cout<<array[p]<<" "<<p;
			p++;
		}
	}
	return 0;
}

		
