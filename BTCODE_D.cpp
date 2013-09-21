#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	unsigned long long int t,M,N,i,j,max_profit=0,k=0,index,max,max_c[100];

	cin>>t;
	while(t--)
	{
		cin>>M>>N;
		unsigned long long A[M][N],B[M][N],C[M][N];
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				cin>>A[i][j];
			}
		}
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				cin>>B[i][j];
			}
		}
		for(i=0;i<M;i++)
		{
			for(j=0;j<N;j++)
			{
				cin>>C[i][j];
			}
		}
		/*
		for(int i=0;i<M;i++)
		{
			cout<<"\n";
			for(int j=0;j<N;j++)
			{
				cout<<A[i][j]<<" ";
			}
		}
		cout<<"\n";
		for(int i=0;i<M;i++)
		{
			cout<<"\n";
			for(int j=0;j<N;j++)
			{
				cout<<B[i][j]<<" ";
			}
		}
		cout<<"\n";
		for(int i=0;i<M;i++)
		{
			cout<<"\n";
			for(int j=0;j<N;j++)
			{
				cout<<C[i][j]<<" ";
			}
		}
		*/
		
		for(i=0;i<M;i++)
		{
			 max=C[i][0];
			for(j=0;j<N;j++)
			{
				if(C[i][j]>max)
				{
					max=C[i][j];
					index=j;
				}
				
			}
			max_c[k++]=index;
		}
		for(i=0;i<k;i++)
		{
			max_profit+=min(A[i][max_c[i]],B[i][max_c[i]])*C[i][max_c[i]];
			
		}
		cout<<max_profit<<"\n";

	}
	return 0;
}
