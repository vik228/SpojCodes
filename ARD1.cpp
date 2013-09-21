#include <iostream>
#include <cstdio>
#define MAX 123456789
using namespace std;
void multiply(long long F[2][2],long long M[2][2]);
void power(long long F[2][2],long long n);
long long fib(long long n)
{
	//cout<<"hiii\n";
	long long F[2][2]={{1,1},{1,0}};
	if(n==0)
		return 0;
	power(F,n - 1);
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
	scanf ("%d",&t);
	while (t--)
	{
		long long n;
		scanf ("%lld",&n);
		if (n == 1LL)
		{
			printf ("3\n");
			continue;
		}
		if (n == 2LL)
		{
			printf ("8\n");
			continue;
		}
		if (n == 3LL)
		{
			printf ("12\n");
			continue;
		}
		n-= 3LL;
		//cout << fib(n+2) << "\n";
		long long ans = (fib(n+2)%MAX + 11LL + (4LL*n)%MAX)%MAX;
		printf ("%lld\n",ans);

	}
}
