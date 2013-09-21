#include<iostream>
#include<cstdlib>
#define MOD 1000000007
using namespace std;
int main()
{
	int a ,b,t;
	int y,u;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		y=1;
		u = a;
		while(b > 0)
		{
			if(b%2 == 1)
				y=(y*u)%MOD;
			u=(u*u)%MOD;
			b/= 2;
			cout<<y<<" "<<u<<endl;
		}
		cout<<y%MOD;
	}
	return 0;
}
			
