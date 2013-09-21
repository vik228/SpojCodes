#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define MAX 74
#define MAX1 73
//#define DEBUG
long long A[MAX];
long long B[MAX1];
using namespace std;
int generate_fib_numbers(long long n)
{
	A[0] = 1;
	A[1] = 1;
	long long i = 2;
	while (1)
	{
		long long res = A[i - 1] + A[i - 2];
		if (res > n)
		{
			break;
		}
		else
		{
			A[i] = res;
			i++;
		}
	}
	return i;

	
}
int main()
{
	int t;
	scanf ("%d",&t);
	unsigned long long val_passed = 1000000000000000LL;
	int p = generate_fib_numbers(val_passed);
	#ifdef DEBUG1
		for (int i = 0; i < p; i++)
			cout << A[i] << "\n";
	#endif
	int j=0;
	for (int i = 1; i < MAX; i++)
	{
		B[j++] = A[i];
	}
	B[72] = B[71] + B[70];
	#ifdef DEBUG
		for (int i = 0; i < MAX1; i++)
			cout << i << ":" << B[i] << "\n";
		exit(0);
	#endif
	while (t--)
	{
		long long n;
		scanf ("%lld",&n);
		long long n1 = 0;
		long long n2 = 0;
		while (n1 < n)
		{
			//cout << "searching " << n - n1 << "\n";
			long long *ptr = lower_bound(B,B+MAX1,n - n1);
			long long idx = ptr - B;
			//cout << "found at " << idx << "\n";
			if (B[idx] != (n - n1))
			{
				n1+= B[idx - 1];
				n2+= B[idx];
			}
			else
			{
				n1+= B[idx];
				n2+= B[idx + 1];
			}
			//exit(0);
		}
		printf ("%lld\n", n2);
	}
	return 0;


}

