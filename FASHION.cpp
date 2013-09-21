#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	int t,t1,input1[1000],input2[1000];
	cin>>t;
	while(t--)
	{
		cin>>t1;
		for(int i=0;i<t1;i++)
			cin>>input1[i];
		sort(input1,input1+t1);
		for(int i=0;i<t1;i++)
			cin>>input2[i];
		sort(input2,input2+t1);
		int sum=0;
		for(int i=0;i<t1;i++)
		{
			sum+=input1[i]*input2[i];
		}
		cout<<sum<<"\n";
	}
	return 0;
}
		
