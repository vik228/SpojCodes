#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int main()
{
	char s[2002];
	stack<char> s1;
	int cas=0;
	while(cin>>s)
	{
		int j;
		int op=0,cl=0;
		if(s[0]=='-')
			break;
		else
		{
			int i=0;
			int opr=0;
			while(s[i]!='\0')
			{
				if(s1.empty())
					s1.push(s[i]);
				else if(s1.top()=='{' && s[i]=='}')
					s1.pop();
				else
					s1.push(s[i]);
				i++;
			}
			cas++;
			while(!s1.empty())
			{
				if(s1.top()=='{')
					op++;
				else
					cl++;
				s1.pop();
			}
//key point to note is that the values of op and cl will be either even or odd..its not possible that one of them is odd and other is even....so in if statement cl%2 as well as op%2 can be used.....
			cout<<op<<"\n"<<cl;
			int ans=op/2+cl/2+((cl%2)?2:0);
			cout<<cas<<"."<<" "<<ans<<"\n";
		}

	}
	return 0;
}

					
