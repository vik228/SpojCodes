#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string s;
	cout<<"Ready\n";
	while(getline(cin,s))
	{
		//cout<<s[0]<<s[1]<<"\n";
		if(s[0]==' ' or s[1]==' ')
		{
		//	cout<<"hiii\n";
			break;
		}
		else
		{
			if(s=="bd" or s=="db" or s=="pq" or s=="qp")
			{	
				cout<<"Mirrored pair\n";
			}
			else
				cout<<"Ordinary pair\n";

		}
	}
	return 0;
}
