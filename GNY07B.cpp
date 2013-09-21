#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int main()
{
	int t;
	cin>>t;
	float val;
	string s1;
	int x=t-1;
	for(int i=1;i<=t;i++)
	{
		cin>>val>>s1;
		if(s1=="kg")
		{
			printf("%d%s",i," ");
			printf("%0.4f",val*2.2046);
			printf("%s%s\n"," ","lb");
		}
		if(s1=="l")
		{
			printf("%d%s",i," ");
			
			printf("%0.4f",val*0.2642);
			printf("%s%s\n"," ","g");
		}
		if(s1=="lb")
		{
			printf("%d%s",i," ");

			printf("%0.4f",val*0.4536);
			printf("%s%s\n"," ","kg");
		}
		if(s1=="g")
		{	
			printf("%d%s",i," ");

			printf("%0.4f",val*3.7854);
			printf("%s%s\n"," ","l");
			x--;
		}
	}
	return 0;
}

	
