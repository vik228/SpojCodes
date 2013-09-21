#include <iostream>
#include <cstdio>
#include <vector>
int L[100010];
int L1[100010];
int L2[100010];
int min1;
using namespace std;
void find_min (int a[], int b[], int k1, int k2)
{
	for (int i = 0, j = k2-3; (i < k1 - 1 and j >= 0); i++, j--)
	{
		int val = 2*a[i] + b[j];
		if (val < min1)
			min1 = val;
	}
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		min1 = 0;
		int N;
		scanf ("%d",&N);
		int sum = 0;
		int k1 = 0;
		for (int i = 0; i < N; i++)
		{
			scanf ("%d",&L[i]);
			sum+= L[i];
			L1[k1++] = sum;
			
		}
		L2[0] = L[N-1];
		sum = L2[0];
		int k = 1;
		for (int i = N-2; i >= 0; i--)
		{
			sum+= L[i];
			L2[k++] = sum;

		}
		/*
		for (int i = 0; i < k1; i++)
			cout << L1[i] << " ";
		cout << "\n";
		for (int i = 0; i < k; i++)
			cout << L2[i] << " ";
		cout << "\n";
		cout << k1 << " "  << k << "\n";
		*/
		min1 = min (L1[k1-2], L2[k-2]);
		find_min (L1, L2,k, k1);
		find_min (L2, L1, k, k1);
		printf ("%d\n", min1);
		
	}
	return 0;
}
