#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <cstdlib>
#define MAX 5010
int input[MAX];
bool val[MAX];
using namespace std;
int main()
{
	int N;
	scanf ("%d",&N);
	for (int i = 0; i < N; i++)
	{
		scanf ("%d",&input[i]);

	}
	int cnt = 0;
	for (int i = 1; i < N; i++)
	{
		if (!val[i])
		{
			int diff = input[i] - input[0];
			int prev = input[i];
			cnt++;
			for (int j = i+1; j < N; j++)
			{
				if (prev + diff == input[j])
				{
					prev = input[j];
					val[j] = true;
					//cnt++;
				}
			}
		}
	}
	printf ("%d",cnt);
	return 0;

}



