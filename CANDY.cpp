#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
int main()
{
	int N;
	scanf ("%d",&N);
	while ( N != -1)
	{
		int input[N];
		int sum = 0;
		for (int i = 0; i < N; i++)
		{
			scanf ("%d",&input[i]);
			sum+= input[i];
		}
		sort (input, input + N);
		if (sum%N != 0)
		{
			printf ("-1\n");
		}
		else
		{
			int n = sum / N;
			int* ptr1 = upper_bound (input, input + N,n);
			int idx1 = ptr1 - input;
			//cout << idx1 << "\n";
			//exit(0);
			int i = idx1;
			int j = 0;
			int count = 0;
			while (i < N)
			{
				while (input[i] != n)
				{
					if(input[j] == n)
						j++;
					else
					{
						input[j]+= 1;
						input[i]-= 1;
						count++;
					}
				}
				i++;

			}
			printf ("%d\n",count);



		}
		scanf ("%d",&N);
	}
	return 0;
}


