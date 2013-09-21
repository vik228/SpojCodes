#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
int find_max(int a,int b)
{
	if (a%b == 0)
	{
		int ret_val = a/b;
		//cout << a/b;
		//exit(0);
		return ret_val;
	}
	else
	{
		int ret_val = a/b+1;
		return ret_val;
	}
}
int main()
{
	int E,F,S,M,E1,F1,S1,M1;
	while (1)
	{
		cin >> E >> F >> S >> M >> E1 >> F1 >> S1 >> M1;
		//cout << E << F << M << E1 << F1 << "\n";
		if (E == -1 or F == -1 or S == -1 or M == -1)
			break;
		if (E == 0 and F == 0 and S == 0 and M == 0)
		{
			printf ("0 0 0 0\n");
			continue;
		}
		int max1,max2,max3,max4;
		max1 = find_max(E,E1);
		max2 = find_max(F,F1);
		max3 = find_max(S,S1);
		max4 = find_max(M,M1);
		
		int max_num1 = max(max1,max2);
		int max_num2 = max(max3,max4);
		//cout << max_num1 << max_num2 << "\n";
		int max_num = max(max_num1,max_num2);

		int ans1 = max_num*E1 - E;
		int ans2 = max_num*F1 - F;
		int ans3 = max_num*S1 - S;
		int ans4 = max_num*M1 - M;
		printf ("%d %d %d %d\n",ans1,ans2,ans3,ans4);

	}
	return 0;
}
