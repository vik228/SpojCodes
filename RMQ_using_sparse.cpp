#include<iostream>
#include<cstdlib>
#include<cmath>
#include <cstdio>
#include <cassert>
using namespace std;

//#define MAXN 100000		// why saving memory, its free! and saves out of bound error
#define MAXN 200100
//long long M[MAXN][16];
long long M[MAXN][20];
long long A[MAXN];

void process2(long long M[MAXN][20], long long A[MAXN], int N)
{
      int i, j;
      for (i = 0; i < N; i++)
          M[i][0] = i;
      for (j = 1; (1 << j) <= N; j++)
          for (i = 0; i + (1 << j) - 1 < N; i++)
              if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
                  M[i][j] = M[i][j - 1];
              else
                  M[i][j] = M[i + (1 << (j - 1))][j - 1];
}
long long RMQ(long long A[], int size, int i, int j)
{

//    process2(M,A,size);			// why preprocessing at each processing.
    int k=0;
    k=log2(j-i+1);		// assertion fails here, CHECK IT.

    if(A[M[i][k]] <= A[M[j-(1<<k)+1][k]])
        return A[M[i][k]];
    else
        return A[M[j-(1<<k)+1][k]];
}
int main()
{
	int T,N,Q,Q1,Q2;
//	cin>>T;
	scanf("%d\n", &T);
	int cas=1;
	while(T--)
	{
//		cin>>N>>Q;
		scanf("%d %d\n", &N, &Q);
		for(int i=0;i<N;i++)
			scanf("%lld ", &A[i]);		// can be executed for 100*10^5 times.
//			cin>>A[i];

    		process2(M,A,N);		// preprocess here

		cout<<"Scenario #"<<cas<<":";
		cout<<"\n";
		while(Q--)
		{
			scanf("%d %d\n", &Q1, &Q2);
			printf("%lld\n", RMQ(A, N, Q1-1, Q2-1));
//			cin>>Q1>>Q2;
//			cout<<RMQ(A,N,Q1-1,Q2-1)<<"\n";
		}
		cas++;
	}
	return 0;
}
