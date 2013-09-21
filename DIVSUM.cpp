#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main()
{
	int t,n;
	scanf("%d",&t);
	//exit(0);
	while(t--)
	{
		int sum=0;
		int x=0;
		scanf("%d",&n);
		if(n==0 || n==1)
		{
			printf("%d\n",0);
		}
		else
		{
			for(int i=1;i*i<=n;i++)
			{
				if(n%i==0)
				{
					sum+=i;
					x=n/i;
					if((x!=i)&&(x<=n/2))
						sum+=x;
				}	
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}
			
	


