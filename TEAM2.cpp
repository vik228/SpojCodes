#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<string>
using namespace std;
int main()
{
	long long int arr[4];
	long long int* ptr;
	ptr=arr;
	int j=1;
	while(scanf("%lld",&arr[0])!=EOF)
	{
		int k=1;
		for(int i=1;i<4;i++)
		{
			cin>>arr[i];
			k++;
		}
		sort(ptr,ptr+k);
		cout<<"Case"<<" "<<j<<":"<<" "<<arr[2]+arr[3]<<"\n";
		j++;
			

	}
	return 0;
}
