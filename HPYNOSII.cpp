#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
typedef long long int int64;
using namespace std;
int convert_to_int (char buff[])
{
	int p = strlen(buff);
	int digit = 0;
	for (int i = 0; i < p; i++)
	{
		digit = (digit*10) + (buff[i] - '0');
	}
	return digit;
}
int find_sum_of_squares (int N)
{
	int ret_val = 0;
	while (N > 0)
	{
		//cout << "hiii\n";
		int64 t = N%10;
		N/= 10;
		ret_val+= t*t;
	}
	return ret_val;

}
int main()
{
	char buff[20];
	char buff1[20];
	gets(buff);
	int T = convert_to_int(buff);
	while (T--)
	{
		//cout << "hii\n";
		int N;
		int count = 0;
		gets(buff1);
		N = convert_to_int(buff1);
		//cout << N << "\n";
		int val = find_sum_of_squares(N);
		count++;
		//cout << val << "\n";
		while (1)
		{
			if (val == 4 or val == 16 or val == 20 or val == 37 or val == 42 or val == 58 or val == 89 or val == 145)
			{
				printf ("-1\n");
				break;
			}
			else if (val == 1)
			{
				printf ("%d\n",count);
				break;
			}
			else
			{
				val = find_sum_of_squares(val);
				count++;
			}
		}


		
	}
	return 0;
}

