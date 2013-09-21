#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
int main()
{
	int T;
	long long N;
	double n1,n2;
	cin>>T;
	while(T--)
	{
		cin>>N;
		n1=log2(N);
		n2=ceil(n1);
		//cout<<n1<<"\n"<<n2;
		//exit(0);
		if(pow(2,n2)==N)
		{
			cout<<N<<" "<<"0"<<"\n";
		}
		else
		{
			long long count=0;
			long long res,final_res;
			res=pow(2,n2);
			final_res=res;
			while(N>0)
			{
				res/=2;
				count++;
				if(N>=res)
					N-=res;
			}
			cout<<final_res<<" "<<count<<"\n";
		}

		
	}
	return 0;
}
