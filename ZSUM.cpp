#include <iostream>
#include <cstdio>
#define MOD 10000007
using namespace std;
typedef long long int64;
int64 modulo(int64 a ,int64 pow)
{
	int64 y,u;
	y=1;
	u=a;
	//cout<<"y"<<" "<<"u"<<" "<<"pow"<<"\n";
	while(pow>0)
	{
		//cout<<y<<" "<<u<<" "<<pow<<"\n";
		if(pow%2==1)
			y=(y*u) % MOD;
		u = (u*u) % MOD;
		pow/=2;
	}
	return y%MOD;

}
int main()
{
	int64 n,k;
	scanf ("%lld%lld",&n,&k);
	while (1)
	{
		if (n == 0 or k == 0)
			break;
		else
		{
			int64 val1 = modulo (n,k);
			int64 val2 = modulo (n - 1,k);
			int64 val3 = modulo (n-1,n-1);
			int64 val4 = modulo (n,n);
			int64 ans = val1%MOD +(2*val2)%MOD +(2*val3)%MOD + (val4)%MOD;
			printf ("%d\n",ans%MOD);
			scanf ("%lld%lld",&n,&k);
		}
	}
	return 0;
}
