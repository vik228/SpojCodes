#include<iostream>
#include<cstring>
#include<stack>
#include<cstdlib>
using namespace std;
string spaces(int n)
{
	string s="";
	for(int i=0;i<n;i++)
	{
		s+=' ';
	}
	return s;
}
int main()
{
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<"*"<<endl;
	}
	else
	{
		stack<string> d;
		int l=(n-1)/2;
		string first=spaces(l)+"*";
		cout<<first<<endl;
		d.push(first);
		for(int i=l-1;i>0;i--)
		{
			string outSpace=spaces(i);
			string inSpace=spaces(l-i-1);
			string s = outSpace + "*" + inSpace + "*" + inSpace + "*" + outSpace;
			cout<<s<<endl;
			d.push(s);
		}
		for(int i=0;i<n;i++)
			cout<<"*";
		cout<<endl;
		while(!d.empty())
		{
			string s=d.top();
			d.pop();
			cout<<s<<endl;
		}
	}
	return 0;
}

	
				
