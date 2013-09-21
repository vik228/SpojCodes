#include<iostream>
#include<cstdlib>
using namespace std;
typedef long long int64;
int main()
{
	int t;
	int64 a,b,c,a1,n,d;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>c;
		bool val=false;
		for(int i=7;val==false;++i)
		{
			if((b-a)%(i-5)==0)
			{
				int64 D=a+b;
				if(D*i==2*c)
				{
					d=(b-a)/(i-5);
					//cout<<d;
					//exit(0);
					a1=a-2*d;
					cout<<i<<"\n";
					for(int k=0;k<i;k++)
					{
						//cout<<a1<<"\n"<<d<<"\n";
						cout<<a1+k*d<<" ";
					}
					cout<<"\n";
					val=true;
				}
			}
		}
	}
	return 0;
}
		
	
