#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int getOperands(string s1)
{
	int digit=0;
	for(int i=0;i<(s1.length());i++)
	{
		if(!isdigit(s1[i]))
			return -1;
		else
		{
			digit=(digit*10)+(s1[i]-'0');
		}
	}
	return digit;
}

using namespace std;
int main()
{
int t,v1,v2,v3;
cin>>t;
string s1,s2,s3,s4,s5;
	while(t--)
	{
		cout<<"\n";
		
		cin>>s1>>s2>>s3>>s4>>s5;
		v1=getOperands(s1);
		v2=getOperands(s3);
		v3=getOperands(s5);
		if(v1<0)
		{
			v1=v3-v2;
			cout<<v1<<"+"<<v2<<"="<<v3<<"\n";
		}
		else if(v2<0)
		{
			v2=v3-v1;
			cout<<v1<<"+"<<v2<<"="<<v3<<"\n";
		}	
		else
		{
			v3=v1+v2;
			cout<<v1<<"+"<<v2<<"="<<v3<<"\n";
		}	
		
	}
		return 0;
	}	



