#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int gcd (int A, int B)
{
	if (B == 0)
		return A;
	else
		return (gcd (B, A%B));
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int A, B;
		scanf ("%d%d",&A,&B);
		int g = gcd (A, B);
		A /= g;
		B /= g;
		printf ("%d %d\n",B, A);
	}
	return 0;
}
