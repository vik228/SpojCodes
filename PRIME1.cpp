#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 32000
int flags[MAX];
int primes[4000];
void generate_primes()
{
	memset(flags,0,sizeof(flags));
	flags[0] = flags[1] = 1;
	for (int i = 2; i*i <= MAX ; i++)
	{
		for (int j = i+i; j < MAX; j+= i)
		{
			flags[j] = 1;
		}
	}
	int k = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (flags[i] == 0)
			primes[k++] = i;
	}
}
int main()
{
	generate_primes();
	#ifdef DEBUG
		for (int i = 0; i < 4000; i++)
		{
			cout << primes[i] << "\n";
		}
	#endif
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		int m,n;
		scanf ("%d%d",&m,&n);
		if (m < 2)
			m++;
		for (int i = m; i <= n; i++)
		{
			bool found = true;
			for (int k = 0; primes[k]*primes[k] <= i; k++)
			{
				if (i%primes[k] == 0)
				{
					found = false;
					break;
				}
			}
			if (found)
				printf("%d\n",i);
		}
	}

	return 0;
}


