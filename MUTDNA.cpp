#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define MAX 1000005
int dp1[MAX],dp2[MAX];
using namespace std;
int find_mutations (string A)
{
	for (int i = 0; i < A.length(); i++)
	{
		if (A[i] == 'A')
		{
			dp1[i+1] = dp1[i];
			dp2[i+1] = 1 + min (dp1[i], dp2[i]);
		}
		else
		{
			dp2[i+1] = dp2[i];
			dp1[i+1] = 1 + min (dp1[i], dp2[i]);
		}
	}
	return dp1[A.length()];
}
int main()
{
	int N;
	scanf ("%d",&N);
	string A;
	cin >> A;
	printf ("%d\n",find_mutations (A));
	return 0;


}
