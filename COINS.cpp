#include<iostream>
#include<map>
#include<cstdio>
#include<algorithm>
using namespace std;
map<int,long long> h;
long long get_max(long long n)
{
	if(n==0)
		return 0;
	long long r=h[n];
	if(r==0)
	{
		r=max(n,get_max(n/2)+get_max(n/3)+get_max(n/4));
		h[n]=r;
	}
	return r;
}

int main()
{
	long long n;
	cin>>n;
	while(!cin.eof())
	{
		long long sum;
		sum=get_max(n);
		cout<<sum<<"\n";
		cin>>n;
	}
	return 0;
}

