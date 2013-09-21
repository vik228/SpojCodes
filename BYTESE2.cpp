#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
	int t;
	scanf ("%d",&t);
	while (t--)
	{
		int N;
		scanf ("%d",&N);
		map < int, int > m1;
		map < int, int >::iterator it;
		int Er_time,Ex_time;
		for (int i = 0; i < N; i++)
		{
			scanf ("%d%d",&Er_time,&Ex_time);
			for (int j = Er_time; j <= Ex_time; j++)
			{
				m1[j]+= 1;
			}
		}
		int max = -1;
		for (it = m1.begin(); it != m1.end(); it++)
		{
			if ((it->second) > max)
				max = it->second;
		}
		printf ("%d\n",max);
	}
	return 0;

}

