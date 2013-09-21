#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int gcd (long long a,long long b)
{
	if (b == 0)
		return a;
	else
		return gcd(b,a%b);

}
int lcm(long long a,long long b)
{
	int t = gcd(a,b);
	return ((a*b)/t);
}
int main()
{
	string s;
	vector <int> v1,v2;
	vector <int>::iterator it,it1;

	while (cin >> s)
	{
		if (s == "*")
			break;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'Y')
				v1.push_back(i + 1);
			else
				v2.push_back(i + 1);
		}
		//bool val = true;
		if (v1.size() > 1)
		{
			it = v1.begin();
			long long num = lcm(*it,*(it + 1));
			it++;
			it++;
			int t = v1.size();
			while (it != v1.end())
			{
				num = lcm(num ,*it);
				it++;
			
			}
			bool val = true;
			if (v2.size() > 0)
			{
				for (it1 = v2.begin(); it1 != v2.end(); it1++)
				{
					if (num % *it1 == 0)
					{
				
						printf ("-1\n");
						val = false;
						break;
					}
				}
			}
			if (val)
				printf ("%lld\n",num);
		}
		else if (v1.size() == 1)
		{
			it = v1.begin();
			bool val = true;
			for (it1 = v2.begin(); it1 != v2.end(); it1++)
			{
				if (*it % *it1 == 0)
				{
					printf ("-1\n");
					val = false;
					break;
				}
			}
			if (val)
				printf ("%d\n",*it);
		}
		else
			printf ("-1\n");
		v1.clear();
		v2.clear();


	}
	return 0;
}
