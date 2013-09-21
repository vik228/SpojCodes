#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int *usr_val,*lhs,*rhs,t,sum=0,it1=0,it2=0,ans=0;
	cin>>t;
	usr_val=new int[t];
	lhs=new int[t*t*t+1];
	rhs=new int[t*t*t+1];
	for(int i=0;i<t;i++)
	{
		cin>>usr_val[i];
	}
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<t;j++)
		{
			for(int k=0;k<t;k++)
			{
				sum=usr_val[i]+usr_val[j];
				if(usr_val[k]!=0)
				{
					rhs[it2]=usr_val[k]*sum;
					it2++;
				}
				lhs[it1]=(usr_val[i]*usr_val[j])+usr_val[k];
				it1++;
			}
		}
	}
	sort(lhs,lhs+it1);
	sort(rhs,rhs+it2);
	for(int i=0;i<it1;i++)
	{
		int val=lhs[i];
		int countl=0;
		while(lhs[i]==val)
		{
			countl++;
			i++;
		}
		i--;
		int *low=lower_bound(rhs,rhs+it2,val);
		int index=low-rhs;
		int countr=0;
		if(index!=it2)
		{
			while(rhs[index]==val)
			{
				countr++;
				index++;
			}
		}
		ans=ans+countl*countr;
	}
	cout<<ans<<"\n";
	return 0;
}
