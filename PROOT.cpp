#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 65536
int is_prime[MAX];
int primes[6600];
using namespace std;
void generate_primes ()
{
	memset (is_prime,0,sizeof (is_prime));
	memset (primes,0,sizeof (primes));
	is_prime[0] = is_prime[1] = 1;
	for (long long i = 2; i*i <= MAX; i++)
	{
		for (int j = i + i; j < MAX; j+= i)
		{
			is_prime[j] = 1;
		}
	}
	int k = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (is_prime[i] == 0)
			primes[k++] = i;
	}
}
long long mod_exp(long long a, long long b, long long n)
{
	long long x = 1, y = a;
	while (b > 0)
	{
		if (b%2 == 1)
		{
			x = (x*y)%n;
		}
		y = (y*y)%n;
		b/= 2;
	}
	return x%n;
}
int main()
{
	generate_primes();
	int n;
	long long P;
	while (scanf ("%lld%d",&P,&n))
	{
		if (P == 0 or n == 0)
			break;
		long long g;
		vector <long long> v1;
		vector <long long>::iterator it;
			//scanf ("%lld",&g);
		long long phi_n = P - 1;
		long long p = phi_n;
		for (int i = 0; (1LL*primes[i]*primes[i]) <= phi_n; i++)
		{
			//cout << primes[i] << "\n";
			if (p% (1LL*primes[i]) == 0)
			{
				v1.push_back(1LL*primes[i]);
				while (p%(1LL*primes[i]) == 0)
				{
					p/= (1LL*primes[i]);
				}
			}
		}
		if (p != 1)
		{
			v1.push_back(p);

		}
		int a = v1.size();
		while (n--)
		{
			scanf ("%lld",&g);
			bool val = true;
			for (it = v1.begin(); it != v1.end(); it++)
			{
				int t = phi_n/(*it);
				if (mod_exp(g,t,P)== 1)
				{
					printf ("NO\n");
					val = false;
					break;
				}
			}
			if (val)
				printf ("YES\n");
		}

	}
	return 0;
}
