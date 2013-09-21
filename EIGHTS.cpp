#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	unsigned long long t,k;
	int a[]={192,442,692,942};
	cin>>t;
	while(t--)
	{
		cin>>k;
		k--;
		cout<<1000*(k/4)+a[k%4]<<"\n";
	}
	return 0;
}
