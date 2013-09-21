#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int t,r;
	double ans;
	scanf("%d",&t);
	int i=1;
	while(t--)
	{
		scanf("%d",&r);
		ans = 0.25 + ((double)r)*((double)r)*4;
		printf("Case %d: %0.2f\n",i,ans);
		i++;
		
	}

}
