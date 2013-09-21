#include <iostream>
#include <algorithm>
#include <cstdio>
#define MAX 100000
using namespace std;
int main()
{
	pair < int, int > vals[MAX];
	int T,N,R,I,C;
	scanf ("%d",&T);
	int j = 1;
	while (T--)
	{
		scanf("%d%d",&N,&R);
		for (int i = 0; i < R; i++)
		{
			scanf ("%d%d",&I,&C);
			vals[i] = make_pair(C,I);
		}
		sort (vals, vals + R);
		#ifdef DEBUG
			for (int i = 0; i < R; i++)
			{
				cout << vals[i].first << "->" << vals[i].second << "\n";
			}
			cout << "\n";
		#endif
		bool repeat = false;
		for (int i = 0; i < R;)
		{
			int count = 0;
			int t1 = vals[i].first;
			int t2 = vals[i].second;
			while(vals[i].first == t1 and vals[i].second == t2)
			{
				//cout << "hii\n";
				count++;
				i++;
			}
			if(count > 1)
			{
				//cout << "vikas \n";
				repeat = true;
				break;
			}
		}
		if(repeat)
		{
			printf("Scenario #%d: impossible\n",j);
			j++;
		}
		else
		{
			 printf("Scenario #%d: possible\n",j);
			 j++;
		}


	}
	return 0;

}
