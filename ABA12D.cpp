#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <algorithm>
#include <cmath>
int arr[1000];
#define MAX2 78500
#define MAX 1000000
unsigned A[MAX>>6];
int primes[MAX2];
#define chk(n) (A[(n)>>6]&(1<<(((n)>>1)&31)))
#define set(n) (A[(n)>>6]|=(1<<(((n)>>1)&31)))
using namespace std;
void sieve()
{
    for (unsigned i = 3; i*i <= MAX; i+= 2)
    {
        int v = chk(i);
        if (v == 0)
		for (unsigned j = i*i,k=i<<1; j < MAX; j+=k)
		{
			set(j);
		}
    }
    int q = 1;
    primes[0] = 2;
    for (unsigned i = 3; i < MAX; i+=2)
    {
        int v = chk(i);
        if (v == 0)
            primes[q++] = i;
    }
    //cout << q << "\n";
}
int pow1 (int n, int i)
{
	if (i == 0)
		return 1;
	else
		return (n*pow (n, i-1));
}
int find_divsum (int n)
{
	int res = 1;
	if (binary_search (primes, primes + MAX2, n))
		return (n + 1);
	for (int i = 0; primes[i]*primes[i] <= n; i++)
	{
		int cnt = 0;
		if (n%primes[i] == 0)
		{
			while (n%primes[i] == 0)
			{
				cnt++;
				n/= primes[i];
			}
			if (cnt > 0)
			{
				res*= (pow1 (primes[i], cnt+1) - 1)/(primes[i] - 1);
			}
		}

	}
	return res;
}

int main()
{
	sieve();
	int idx = 0;
	arr[idx++] = 2;
	for (int i = 1; i*i <= MAX; i++)
	{
		unsigned t = find_divsum(i*i);
		//cout << t << "\n";
		if (binary_search (primes, primes + MAX2,t))
			arr[idx++] = i*i;
			
	}

	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int A, B;
		scanf ("%d%d",&A,&B);
		int i1 = lower_bound (arr, arr + idx, A) - primes;
		int i2 = lower_bound (arr, arr + idx, B) - primes;
		i2 = i2 - 1;
		printf ("%d\n",(i2 - i1 + 1));

	}
	return 0;
}
