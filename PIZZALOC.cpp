#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int distances[22][102],deg_m[20];
struct coordinates
{
	int x,y;
}c1[20];
struct solitairs
{
	int x1,y1,no_people;
}s1[20];
int bit_count(int x)
{
	int c;
	for (c = 0; x; c++)
		x&= x-1;
	return c;
}
int main()
{
	int K,R;
	scanf ("%d%d",&K,&R);
	int M;
	scanf ("%d",&M);
	//coordinates c1[M];
	for (int i = 0; i < M; i++)
	{
		scanf ("%d%d",&c1[i].x,&c1[i].y);
	}
	int N;
	scanf ("%d",&N);
	//solitairs s1[N];
	int used[N];
	for (int i = 0; i < N; i++)
	{
		scanf ("%d%d%d",&s1[i].x1,&s1[i].y1,&s1[i].no_people);
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if ((c1[i].x - s1[j].x1)*(c1[i].x - s1[j].x1) + (c1[i].y - s1[j].y1)*(c1[i].y - s1[j].y1) <= R*R)
			{
				distances[i][deg_m[i]++] = j;
			}
		}
	}
	int max_val = 0;
	for (int i = 1; i <= (1<<M); i++)
	{
		if (bit_count(i) == K)
		{
			int count = 0;
			memset (used,0,sizeof(used));
			for (int j = 0; j < M; j++)
			{
				if (i & (1<<j))
				{
					for (int k = 0; k < deg_m[j]; k++)
					{
						if (used[distances[j][k]] != 1)
						{
							count+= s1[distances[j][k]].no_people;
							used[distances[j][k]] = 1;
						}
					}

				}
			}
			max_val = max(max_val,count);
		}
	}
	printf ("%d\n",max_val);
	return 0;
}
