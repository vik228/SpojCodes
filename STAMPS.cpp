#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	int scn = 0;
	while (T--)
	{
		scn++;
		int N_s,N_f;
		scanf ("%d%d",&N_s,&N_f);
		int input[N_f];
		for (int i = 0; i < N_f; i++)
		{
			scanf ("%d",&input[i]);
		}
		sort (input,input+N_f);
		int i = N_f - 1;
		int j = 0;
		while (N_s > 0 and i >= 0)
		{
			N_s -= input[i];
			//cout << N_s << "\n";
			i--;
			j++;
		}
		if (N_s > 0)
			printf ("Scenario #%d:\nimpossible\n\n",scn);
		else
			printf ("Scenario #%d:\n%d\n\n",scn,j);
	}
	return 0;
}
