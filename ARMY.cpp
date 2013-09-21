#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int T,NG,NM;
	scanf ("%d",&T);
	while (T--)
	{
		scanf ("%d%d",&NG,&NM);
		int n1[NG],n2[NM];
		for (int i = 0; i < NG; i++)
		{
			scanf ("%d",&n1[i]);
		}
		for (int i = 0; i < NM; i++)
		{
			scanf ("%d",&n2[i]);
		}
		sort (n1, n1 + NG);
		sort (n2, n2 + NM);
		int m1 = n1[NG - 1];
		int m2 = n2[NM - 1];
		if (m1 >= m2)
			printf("Godzilla\n");
		else
			printf("MechaGodzilla\n");
	}
	return 0;
}
