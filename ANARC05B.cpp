#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
int a[10000];
int b[10000];
using namespace std;
int main()
{	
	long long n1,n2;
	while (scanf ("%lld", &n1))
	{
		if (n1 == 0)
			break;
		memset (a, 0, sizeof(a));
		for (long long i = 0; i < n1; i++)
			scanf ("%d", &a[i]);
		scanf ("%lld", &n2);
		memset (b, 0, sizeof(b));
		for (long long i = 0; i < n2; i++)
			scanf ("%d", &b[i]);
		long long start1,start2;
		long long sum = 0;
		long long found = 0;
		bool intersect = false;
		for (long long i = 0; i < max(n1,n2); i++)
		{
			if (binary_search(b, b + n2, a[i]))
			{
				intersect = true;
				found++;
				if(found == 1)
				{
					int* ptr1 = lower_bound (b, b + n2, a[i]);
					long long low1 = ptr1 - b;
					start1 = low1;
					start2 = i;
					long long s1 = 0,s2 = 0;
					for (long long k1 = 0; k1 < i; k1++)
					{
						s1+= a[k1];
					}
					for (long long k2 = 0; k2 < low1; k2++)
					{
						s2+= b[k2];
					}
					sum+= max(s1,s2);
				}
				else
				{
					int* ptr2 = lower_bound (b , b + n2, a[i]);
					long long low = ptr2 - b;
					long long s1 = 0, s2 = 0;
					for (long long k1 = start1; k1 < low; k1++)
					{	
						s2+= b[k1];
					}
					for (long long k2 = start2; k2 < i; k2++)
					{
						s1+= a[k2];
					}

					sum+= max(s1,s2);
					start1 = low;
					start2 = i;
					
				}

			}
		}
		if (intersect)
		{
			long long sum1 = 0, sum2 = 0;
			for (long long t1 = start2; t1 < n1; t1++)
				sum1+= a[t1];
			for (long long t2 = start1; t2 < n2; t2++)
				sum2+= b[t2];
			sum+= max(sum1,sum2);
	
			printf("%lld\n",sum);
		}
		else
		{
			long long s1 = 0,s2 = 0;
			for (long long i = 0; i < n1; i++)
				s1+= a[i];
			for (long long i = 0; i < n2; i++)
				s2+= b[i];
			sum+= max(s1,s2);
			printf("%lld\n",sum);
		}
			
	}
	return 0;
}



