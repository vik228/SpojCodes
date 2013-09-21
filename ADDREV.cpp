#include<iostream>
#include<cstring>
using namespace std;
int getRevNumber(string s)
{
	int digit=0;
	for(int i=(s.length()-1);i>=0;i--)
		digit=(digit*10)+(s[i]-'0');
		return digit;
}
int main()
{
	int t;
	string s1,s2;
	int n1,n2,sumInt;
	cin>>t;
	while(t--)
	{
		int result=0;
		cin>>s1>>s2;
		n1=getRevNumber(s1);
		n2=getRevNumber(s2);
		sumInt=n1+n2;
		while(sumInt>0)
		{
			result=result*10+sumInt%10;
			sumInt/=10;
		}
		cout<<result<<"\n";
			
		
	}
	return 0;
}

