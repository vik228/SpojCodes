#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#define MAXN 1000000
#define MAXN2 100000
int M[MAXN][24];
int A[MAXN];
using namespace std;
void process2(int N)
{
      int i, j;
      for (i = 0; i < N; i++)
          M[i][0] = i;
      for (j = 1; 1 << j <= N; j++)
          for (i = 0; i + (1 << j) - 1 < N; i++)
              if (A[M[i][j - 1]] > A[M[i + (1 << (j - 1))][j - 1]])
                  M[i][j] = M[i][j - 1];
              else
                  M[i][j] = M[i + (1 << (j - 1))][j - 1];
}
int RMQ(int i,int j)
{
	int k=0;
	k = log2 (j-i+1);
	if(A[M[i][k]] >= A[M[j-(1<<k)+1][k]])
		return A[M[i][k]];
	else
		return A[M[j-(1<<k)+1][k]];
}
int main()
{
	int n;
	scanf ("%d",&n);
	for (int i = 0; i < n; i++)
		scanf ("%d",&A[i]);
	process2 (n);
	int k;
	cin >> k;
	for (int i = 0; k <= n; i++,k++)
		printf ("%d ",RMQ(i,k-1));

	return 0;
}
