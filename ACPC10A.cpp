#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int a1,a2,a3;
	while(cin>>a1>>a2>>a3)
	{
		if(a1==0 && a2 == 0 && a3 == 0)
			break;
		if((a2-a1) == (a3-a2))
			cout<<"AP"<<" "<<a3+(a3-a2)<<"\n";
		else if(a2%a1 == a3%a2)
			cout<<"GP"<<" "<<a3*(a3/a2)<<"\n";
	}
	return 0;
}
