#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long find_num (string s,int idx)
{
	int dig = 0;
	int i = idx;
	while (isdigit(s[i]))
	{
		dig = dig*10 + s[i] - '0';
		i++;
	}
	return dig;
}
int count (string s, int idx)
{
	int i = idx;
	while (isdigit(s[i]))
	{
		i++;
	}
	int cnt = i - idx;
	return cnt;
}
int main()
{
	int T;
	scanf ("%d",&T);
	char ch;
	while (T--)
	{
		string s;
		cin >> ch;
		while (ch != '=')
		{
			if (ch != ' ')
				s+= ch;
			cin >> ch;
		}
		
	#ifdef DEBUG
		cout << s.length() << "\n";
		for (int i = 0; i < s.length(); i++)
			cout << s[i] << "\n";
	#endif
		long long ans = 0;
		for (int i = 0; i < s.length();)
		{
			if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/')
			{
	
				if (s[i] == '+')
				{
					//cout << ans << "+" << s[i + 1] - '0' <<"\n"; 
					ans+= find_num (s, i + 1);
					i+= count(s,i + 1) + 1;
				}
				else if (s[i] == '*')
				{
					//cout << ans << "\n";
					ans*= find_num (s, i + 1);
					//cout << ans << "\n";
					//cout << count (s, i + 1) << "\n";
					i+= count(s, i + 1) + 1;
					//cout << s[i] << "\n";
				}
				else if (s[i] == '-')
				{
					ans-= find_num (s, i + 1);
					i+= count (s, i + 1) + 1;
				}
				else
				{
					ans/= find_num (s, i + 1);
					i+= count (s, i + 1) + 1;
				}
			}
			else
			{
				ans = find_num (s,0);
				i+= count (s,0);
				//cout << ans << "\n" << s[i] << "\n";
			}
		
		
		}

		printf ("%lld\n",ans);
	}



	return 0;
}
