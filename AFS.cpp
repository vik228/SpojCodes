#include<iostream>
#include<cstdio>
#include <cstdlib>
using namespace std;
#define MAX 1000010
int a[MAX];
long long int arr[MAX];
void factor()
{
    	int i,j;
	a[0] = 1;
	for(i = 1 ; i<= MAX ; i++)
		a[i] = i ;
	for(i=2 ; i*i<MAX ; i++)
	{
		if(a[i] == i)
		{
			for(j= i*i ; j <= MAX ; j += i)
			{
				if(a[j] == j)
					a[j] = i;
			}
		}
	}
	//cout << " a of 2 iis " << a[2] << endl ;
	/*for(i=1 ; i<= MAX ; i++)
		if(!a[i])
			cout << i<< "  " << a[i] << endl ;*/
	//cout << " factr ends " << endl ;
}

long long fun(long long n)
{
	int k = a[n];
	long long div_sum = 1;
	long long div = 1;
	while (n > 1)
	{
		div_sum*= k;
		n/= k;
		if (k != a[n])
		{
			div_sum*= k;
			div*= (div_sum - 1)/(k-1);
			div_sum = 1;
			k = a[n];
		}
	}
	return div;
}

void seq()
{
	int i,j;
	arr[0] = 0;arr[1] = 0;
	for(i = 2 ; i < MAX ; i++)
	{
		arr[i] = arr[i-1] + fun(i) - i;
	}
}
int main()
{
	factor();
	//cout << fun(220LL) << "\n";
	//exit(0);
	seq();
	int t;
	long long n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",arr[n]);
	}
	return 0;
}
