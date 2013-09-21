#include<iostream>
#include<cstring>
#include<string.h>
#include<cmath>
#include<cstdio>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	int t,a;
	string b;
	scanf("%d",&t);
	while(t--)
	{
		cin>>a>>b;
		if(a!=0)
		{
			int dig=0;
			for(int i=0;i<b.length();i++)
			{
				dig=(dig*10+b[i]-'0')%a;
				
				
			}
			//cout<<dig<<"\n";
			printf("%d\n",gcd(a,dig));
		}
		else
		{
			for(int i=0;i<b.length();i++)
			{
				printf("%c",b[i]);
			}
			printf("\n");
		}
	}
	return 0;
	
}
