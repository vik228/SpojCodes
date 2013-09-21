#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	
	int a[5010],b[5010],c[5010]; 
	string s1;
	int t1;
	while(cin>>s1)
	{
		cout<<"\n";
		if(s1[0]=='0')
			break;
		for(int i=0;i<s1.length();i++)
			a[i]=s1[i]-'0';
		for(int j=1;j<s1.length();j++)
			b[j]=(a[j-1]*10)+a[j];
		c[0]=1;
		if(a[1])
			c[1]=1;
		else
			c[1]=0;
		if(b[1]>9 && b[1]<27)
			c[1]++;
		for(int i=2;i<s1.length();i++)
		{
			if(a[i])
				c[i]=c[i-1];
			else
				c[i]=0;
			if(b[i]>9 && b[i]<27)
				c[i]+=c[i-2];
		}
		int n=s1.length();
		cout<<c[n-1];
	}
	return 0;
}
			

