#include<iostream>
#include<stack>
#include<cstdlib>
#include <string.h>
#define MAXSIZE 400
using namespace std;
int prcd(char c1,char c2)
{
	//cout<<"The arguments passed are:"<<c1<<"and"<<c2<<endl;
	if(c1=='+' && c2=='-')
		return 0;
	else if(c1=='+' && c2=='*')
		return 0;
	else if(c1=='+' && c2=='/')
		return 0;
	else if(c1=='+' && c2=='^')
		return 0;
	else if(c1=='-' && c2=='*')
		return 0;
	else if(c1=='-' && c2=='/')
		return 0;
	else if(c1=='-' && c2=='^')
		return 0;
	else if(c1=='*' && c2=='/')
		return 0;
	else if(c1=='*' && c2=='^')
		return 0;
	else if(c1=='/' && c2=='^')
		return 0;
	else if(c1=='(')
		return 0;
	else if(c2==')')
		return 1;
	else if(c2=='(')
		return 0;
	else if(c1=='(' && c2==')')
		return 0;
	else 
		return 1;
}
		
int main()
{
	//cout<<"hello";
	int t;
	cin>>t;
	while(t>0)
	{
		stack<char>s1;
		char a[MAXSIZE];
		char b[MAXSIZE];
		cin>>a;
		char op;
		int i=0;
		int p=0;
		int m1 = strlen(a);
		//cout<<"jiii";
		while(a[i] != '\0')
		{
			cout << "\nhii";
		
			if(a[i]!='+' && a[i]!='-' && a[i]!='*' && a[i]!='/' && a[i]!='^' && a[i]!='(' && a[i]!=')')
			{	
			//cout<<"pushing:"<<a[i]<<"into the array b at index:"<<p<<endl;
				b[p]=a[i];
				p++;
			}
			else
			{
				while(!s1.empty() && prcd(s1.top(),a[i]))
				{
					cout << "hii\n";
					op=s1.top();
					if(op=='(')
						s1.pop();
					else
					{
					//cout<<"The top Element of the stack is:"<<op<<endl;
						b[p]=op;
						s1.pop();
						p++;
						if(s1.top()=='(')
							s1.pop();
					}	
			
				}
			//cout<<"Pushing:"<<a[i]<<"into the stack\n";
				if(a[i]!=')')
					s1.push(a[i]);
			}
			i++;
		}
		cout << "bahar\n";
		while(!s1.empty())
		{
			cout << "hii\n";
			op=s1.top();
			if(op=='(')
				s1.pop();
			else
			{
			//cout<<"pushing"<<op<<"into the array b at index:"<<p<<endl;
				b[p++]=op;
				s1.pop();
			}
		}	
		for(int j=0;j<p;j++)
			cout<<b[j];
		cout<<"\n";
		t--;
	}

	return 0;
}
		
		
