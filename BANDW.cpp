#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
	string S,T;
	cin >> S >> T;
	while (1)
	{
		if (S == "*" or T == "*")
			break;
		int cnt = 0;
		bool toChange = false;
		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] != T[i] and !toChange)
			{
				cnt++;
				toChange = true;
			}
			if (S[i] == T[i])
				toChange = false;
		}
		printf ("%d\n",cnt);
		cin >> S >> T;
	}
}
