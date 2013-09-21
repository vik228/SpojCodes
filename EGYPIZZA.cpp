#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int N;
	scanf ("%d",&N);
	//int t = N - 1;
	string s;
	int cnt1 = 0, cnt2 = 0,cnt3 = 0;
	while (N--)
	{
		cin >> s;
		if (s == "1/2")
			cnt1++;
		if (s == "3/4")
			cnt2++;
		if (s == "1/4")
			cnt3++;
	}
	int count = 0;
	if (cnt2 > 0)
	{
		if (cnt3 > cnt2)
		{
			cnt3 = cnt3-cnt2;
			count+= cnt2;
		}
		else
		{
			cnt3 = 0;
			count+= cnt2;
		}
	}
	if (cnt1 > 0)
	{
		if (cnt1 % 2 == 0)
		{
			count+= cnt1/2;
		}
		else
		{
			count += (cnt1/2 + 1);
			cnt3 -= 2;

		}
	}
	if (cnt3 > 0)
	{
		if (cnt3 <= 4)
		{
			count+= 1;
		}
		else 
		{
			if (cnt3 % 4 == 0)
			{
				count += cnt3/4;
			}
			else
			{
				count += (cnt3/4 + 1);
			}
			
		}
	}
	printf ("%d\n",count + 1);
	return 0;
}
