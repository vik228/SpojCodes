#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long n;
	while(cin>>n)
	{
		if(n==0)
		{
		//	cout<<"hii";
			break;
		}
		for(long long i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				int p=0;
				while(n%i==0)
				{
					p++;
					n=n/i;
				}
				cout<<i<<"^"<<p<<" ";
			}
		}
		if(n>1)
			cout<<n<<"^"<<1;
		cout<<"\n";
	}
	return 0;
}

				
