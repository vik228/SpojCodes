#include<iostream>
#include<cmath>
#define MAX 1000000007
using namespace std;
void multiply(long long F[2][2],long long M[2][2]);
void power(long long F[2][2],long long n);
long long fib(long long n)
{
	//cout<<"hiii\n";
	long long F[2][2]={{1,1},{1,0}};
	if(n==0)
		return 0;
	power(F,n-1);
	return F[0][0]%MAX;
}
void multiply(long long F[2][2],long long M[2][2])
{
	//cout<<"hiii\n";
	long long x = ((F[0][0]*M[0][0]) + (F[0][1]*M[1][0]))%MAX;
	long long y =  ((F[0][0]*M[0][1]) + (F[0][1]*M[1][1]))%MAX;
	long long z =  ((F[1][0]*M[0][0]) + (F[1][1]*M[1][0]))%MAX;
    	long long w =  ((F[1][0]*M[0][1]) + (F[1][1]*M[1][1]))%MAX;
     
       	F[0][0] = x;
        F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
	
}
void power(long long F[2][2], long long n)
{
  	if( n == 0 || n == 1)
  		return;
	long long M[2][2] = {{1,1},{1,0}};
	   
	power(F, n/2);
	multiply(F, F);
	        
	if( n%2 != 0 )
	multiply(F, M);
}
int main()
{
	int t;
	long long n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==0)
		{
			cout<<"0"<<"\n";
			continue;
		}
		if(n==1)
		{
			cout<<"2"<<"\n";
			continue;
		}
		cout<<(fib(n+3))<<"\n";

	}
	return 0;
}
