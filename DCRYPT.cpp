#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int key;
		string msg, ans;
		scanf ("%d",&key);
		cin >> msg;
		if (key <= 25)
		{
			for (int i = 0; i < msg.length(); i++)
			{
				if (msg[i] != '.')
				{
					if (islower (msg[i]))
					{
						msg[i] -= 'a';
						msg[i] = (char)((msg[i] + key)%26);
						msg[i] += 'a';
					}
					else
					{
						msg[i] -= 'A';
						msg[i] = (char)((msg[i] + key)%26);
						msg[i] += 'A';
					}
				}
				else
				{
					msg[i] = ' ';
				}
			}
		}
		else
		{
			for (int i = 0; i < msg.length(); i++)
			{
				if (msg[i] != '.')
				{
					if (islower (msg[i]))
					{
						msg[i] -= 'a';
						msg[i] = (char)((msg[i] + key)%26);
						msg[i] += 'A';
					}
					else
					{
						msg[i] -= 'A';
						msg[i] = (char)((msg[i] + key)%26);
						msg[i] += 'a';
					}
				}
				else
					msg[i] = ' ';
			}
		}
		cout << msg << "\n";
	}
	return 0;
}
