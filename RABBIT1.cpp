#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
void multiply(long long F[2][2],long long M[2][2], long long MAX);
void power(long long F[2][2],long long n, long long MAX);
long long fib(long long n, long long int MAX)
{
	//cout<<"hiii\n";
	long long F[2][2]={{1,1},{1,0}};
	if(n==0)
		return 0;
	power(F,n-1,MAX);
	return F[0][0]%MAX;
}
void multiply(long long F[2][2],long long M[2][2], long long MAX)
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
void power(long long F[2][2], long long n, long long MAX)
{
  	if( n == 0 || n == 1)
  		return;
	long long M[2][2] = {{1,1},{1,0}};
	   
	power(F, n/2, MAX);
	multiply(F, F, MAX);
	        
	if( n%2 != 0 )
	multiply(F, M, MAX);
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		long long int N, M;
		scanf ("%lld%lld",&N,&M);
		long long int MOD = 1 << M;
		//cout << MOD << "\n";
		printf ("%lld\n",fib ((N + 1), MOD));

	}
	return 0;
}
