#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
int main()
{
	int ni,t;
	cin>>t;
	while(t--)
	{
		cin>>ni;
		int it=0;
		int *arr;
		arr=new int[ni];
		for(int i=0;i<ni;i++)
		{
			cin>>arr[i];
			it++;
		}
		sort(arr,arr+it);
		if(arr[0]==2 && arr[1]==3 && ni==2)
			cout<<arr[0]<<" "<<arr[1];
		else if(arr[0]==1)
		{
			int j=0;
			while(arr[j]==1)
			{
				cout<<arr[j]<<" ";
				j++;
			}
			if((arr[j]==2) && (arr[j+1]==3) && (ni==(j+2)))
				cout<<arr[j]<<" "<<arr[j+1];
			else
			{
				for(int i=ni-1;i>=j;i--)
				{
					cout<<arr[i]<<" ";
				}
			}
					
		}
		else
		{
			for(int i=0;i<ni;i++)
			{
				cout<<arr[it-1]<<" ";
				it--;
			}
		}
		cout<<"\n";
		delete[] arr;
	}
	return 0;
}
		
		
