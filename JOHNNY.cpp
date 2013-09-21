#include<iostream>
#include<algorithm>
#include<set>
#include<cstdlib>
#include<cmath>
int input[10001];
int indices[10001];
using namespace std;
int main()
{
	int n;
	set<int> myset;
	set<int>::iterator it;
	int* ar_ptr;
	ar_ptr=input;
	cin>>n;
	int sum=0,half_sum,sorted_sum=0,min_diff=0;
	for(int i=0;i<n;i++)
	{
		cin>>input[i];
		sum+=input[i];
		indices[input[i]]=i+1;
	}
	half_sum=sum/2;
	sort(ar_ptr,ar_ptr+n);
	sorted_sum+=input[0];
	min_diff=abs(sorted_sum-half_sum);
	myset.insert(indices[input[0]]);
	for(int i=1;i<n;i++)
	{
		if(sorted_sum<half_sum)
		{
			sorted_sum+=input[i];
			//myset.insert(indices[input[i]]);
			int temp=abs(sorted_sum-half_sum);
			//cout<<temp<<"\n";
			if(temp<=min_diff)
			{
				min_diff=temp;
				//cout<<min_diff<<"\n";
				myset.insert(indices[input[i]]);
			}
		}
		else
		{
			break;
		}
			
	}
	for(it=myset.begin();it!=myset.end();it++)
		cout<<*it<<endl;

		
	return 0;
}
