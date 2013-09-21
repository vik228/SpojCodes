#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 1010
int in_deg[MAX];
int out_deg[MAX];
int main()
{
	int N;
	int k = 0;
	while (scanf ("%d",&N))
	{
		memset(in_deg, 0, sizeof (in_deg));
		memset (out_deg, 0, sizeof (out_deg));
		//scanf ("%d",&N);
		k++;
		if (N == 0)
			break;
		int cost;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf ("%d",&cost);
				out_deg[i]+= cost;
				in_deg[j]+= cost;
			}
		}
	/*
	for (int i = 0; i < N; i++)
		cout << (char)('A' + i) << " out " << out_deg[i] << " in " << in_deg[i] << "\n";
	*/
		int total = 0;
		int ans = 0;
		for (int i = 0; i < N; i++)
		{
			total+= in_deg[i];
			if ((in_deg[i] - out_deg[i])  > 0)
				ans+= in_deg[i] - out_deg[i];
		}
		printf ("%d. %d %d\n",k,total,ans);
	}
		return 0;
}
