#include<iostream>
#include<cstdlib>
using namespace std;
int find_zeros(int n)
{
	int ret=0;
	for(int p=5;p<=n;p*=5)
		ret+=n/p;
	return ret;
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int ans=0;
		ans = find_zeros(n);
		cout<<ans<<"\n";
	}
	return 0;
}

