#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define MAX 10050
#define MAX2 1300
int flag[MAX];
int primes[MAX2];
void sieve ()
{
	flag[0] = flag[1] = 1;
	for (int i = 2; i*i <= MAX; i++)
	{
		for (int j = i+i; j <= MAX; j+= i)
		{
			flag[j] = 1;
		}
	}
	int cnt = 0;
	for (int i = 0; i < MAX; i++)
	{
		if (flag[i] == 0)
			primes[cnt++] = i;
	}
}
int main()
{
	sieve();
	int N;
	scanf ("%d",&N);
	/*
	for (int i = 0; i <= MAX2; i++)
	{
		cout << primes[i] <<"\n";
	}
	exit(0);
	*/
	for (int i = 0; (primes[i] > 0 and primes[i] <= N); i++)
	{
		int num = N;
		int count = 0;
		if (primes[i] == 0)
			cout << primes[i] << "\n";
		while (num > 0)
		{
			num/= primes[i];
			count+= num;
		}
		if (i == 0)
			printf ("%d^%d ", primes[i],count);
		else
			printf (" * %d^%d ",primes[i],count);
	}
	cout << "\n";

	return 0;
}
