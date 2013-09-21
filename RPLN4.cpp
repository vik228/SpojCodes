#include<iostream>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#define MAXN 100000
#define MAXLOGN 524288
int M[MAXLOGN];
int A[MAXN];
using namespace std;
void initialize(int node,int start,int end)
{
	if(start==end)
		M[node]=start;
	else
	{
		//cout<<"hiii\n";
		int mid=(start+end)/2;
		initialize(2*node,start,mid);
		initialize(2*node+1,mid+1,end);
		if(A[M[2*node]] <= A[M[2*node+1]])
			M[node] = M[2*node];
		else
			M[node]= M[2*node+1];
	}
}
int query(int node,int start,int end,int i,int j)
{
	int id1,id2;
	if(i>end or j<start)
		return -1;
	if(start>=i and end<=j)
		return M[node];
	int mid=(start+end)/2;
	id1 = query(2*node,start,mid,i,j);
	id2 = query(2*node+1,mid+1,end,i,j);
	if(id1==-1)
		return id2;
	if(id2==-1)
		return id1;
	if(A[id1]<=A[id2])
		return id1;
	else
		return id2;
}
int main()
{
	int T,N,Q,Q1,Q2;
	scanf("%d",&T);
	int cas=1;
	while(T--)
	{
		scanf("%d%d",&N,&Q);
		for(int i=0;i<N;i++)
			scanf("%d",&A[i]);
		memset(M,-1,sizeof(M));
		initialize(1,0,N-1);
		//cout<<"hii\n";
		printf("Scenario #%d:\n\n",cas);
		while(Q--)
		{
			scanf("%d%d",&Q1,&Q2);
			printf("%d\n",A[query(1,0,N-1,Q1-1,Q2-1)]);
		}
		cas++;
	}
	return 0;
}
