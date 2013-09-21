#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int count[129];
int convert_to_num (string n)
{
	int dig = 0;
	for (int i = 0; i < n.length(); i++)
	{
		dig = dig*10 + (n[i] - '0');
	}
	return dig;
}
int main()
{
	string n;
	while (getline (cin, n))
	{
		int N = convert_to_num (n);
		string s, s1;
		memset (count , 0, sizeof (count));
		if (N == 0)
			break;
		int i = 0, j = 0, cnt = 0, max_len = 0, spc_count = 0, len = 0;
		getline (cin, s);
		while (j < s.length())
		{
			if (count[(int)s[j]] == 0 and cnt < N)
			{
				len++;
				count[(int)s[j]]++;
				cnt++;
				j++;
			}
			else if (count[(int)s[j]] >= 1)
			{
				len++;
				count[(int)s[j]]++;
				j++;
			}
			else if (cnt == N)
			{
				max_len = max (len, max_len);
				while (cnt == N)
				{
					if (count[(int)s[i]] == 1)
					{
						len -= 1;
						count[(int)s[i]] -= 1;
						i++;
						cnt-= 1;
					}
					else if (count[(int)s[i]] > 1)
					{
						len -= 1;
						count[(int)s[i]] -= 1;
						i++;
					}
				}
			}
		}
		max_len = max (max_len, len);
		printf ("%d\n",max_len);
	}
		
	return 0;
}
