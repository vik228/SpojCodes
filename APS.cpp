#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 10000000
int f[MAX];
long long int a[MAX + 2];
void sieve()
{
	f[1] = 1;
	for (long long int i = 2; i <= MAX; i++)
	{
		//cout << "hii\n";
		if (!f[i])
		{
			f[i] = i;
			for (long long int j = i; j*i <= MAX; j++)
			{
				if (!f[j*i])
					f[j*i] = i;
			}
		}
	}
	//cout << "hello\n";
}
void compute ()
{
	a[0] = a[1] = 0;
	for (long long int i = 2; i <= MAX; i++)
	{
		a[i] = a[i-1] + f[i];	
	}
}
int main()
{
	int T;
	sieve();
	compute();
	scanf ("%d",&T);
	while (T--)
	{
		int N;
		scanf ("%d",&N);
		printf ("%lld\n",a[N]);
	}
	return 0;

}
