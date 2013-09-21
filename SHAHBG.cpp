#include <iostream>
#include <cstdio>
#define MAX 20010
bool pos[MAX];
using namespace std;
int main()
{
	int N;
	scanf ("%d",&N);
	int Q;
	int prev_group_count;
	for (int i = 0; i < N; i++)
	{
		scanf ("%d", &Q);
		if (i == 0)
		{
			pos[Q] = true;
			prev_group_count = 1;
		}
		else
		{
			pos[Q] = true;
			if (pos[Q+1] and pos[Q-1])
			{
				prev_group_count-= 1;
			}
			else if (!pos[Q+1] and !pos[Q-1])
			{
				prev_group_count+= 1;
			}

		}
		printf ("%d\n",prev_group_count);
	}
	printf ("Justice\n");
	return 0;
}

