#include <iostream>
#include <cstdio>
#define MAX 1000010
#define INF 1000000000
using namespace std;
int input[MAX];
long long pred (int val, int N)
{
	//cout << val << "\n";
	long long cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (input[i] > val)
			cnt += (long long)(input[i] -val);
	
	}
	return cnt;
}
int bsearch (int lo, int hi, long long M, int N)
{
	int mid;
	long long ret_val;
	for (int i = 0; i < 20; i++)
	{
		//cout << lo << ":" << hi << "\n";
		mid  = (hi + lo)/2;
		ret_val = pred (mid, N);
		if (ret_val < M)
		{
			hi = mid;
		}
		else 
			lo = mid;

	}
	return lo;
}
int main()
{
	int N;
	long long M;
	int high = 0;
	scanf ("%d%lld",&N,&M);
	for (int i = 0; i < N; i++)
	{
		scanf ("%d",&input[i]);
		if (input[i] > high)
			high = input[i];
	}
	printf ("%d\n",bsearch (0, high, M, N));
	return 0;
}



