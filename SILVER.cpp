#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int x;
	int n;
	while(cin>>n)
	{
		if(n==0)
			break;
		else
		{
			x=log2(n);
			cout<<x<<"\n";
		}
	}
	return 0;
}
