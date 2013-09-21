#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 10000000
#define MAX3 13175
int flag[MAX];
int vals[MAX3];
using namespace std;
bool isPrime (int n)
{
	//cout << n << "\n";
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i*i <= n; i+= 2)
	{
		//cout << "hiii\n";
		if (n%i == 0)
			return false;
	}
	return true;
}
void sieve()
{
	for (int i = 1; i*i <= MAX; i++)
	{
		for (int j = 1; ((j*j*j*j)+(i*i)) <= MAX; j++)
		{
			//cout << i << " : " << j << "\n";
			int t = (i*i) + (j*j*j*j);
			if (isPrime(t))
			{
				//cout << t << "\n";
				flag[t] = 1;
			}
			//cout << " returned " << "\n";
		}
	}
	int k = 0;
	//cout << "vikas\n";
	for (int i = 0; i < MAX; i++)
	{
		if (flag[i] == 1)
			vals[k++] = i;
	}
}
int main()
{
	sieve();
	/*
	cout << "Back \n";
	//sieve1();
	for (int i = 0; i <= MAX3; i++)
		cout << i << " : " << vals[i] << "\n";
	exit(0);
	*/
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int n;
		scanf ("%d",&n);
		if (n == 1)
		{
			printf ("0\n");
			continue;
		}
		int idx = (upper_bound (vals, vals + MAX3, n) - vals);
		printf ("%d\n",idx);
	}
	return 0;
}

