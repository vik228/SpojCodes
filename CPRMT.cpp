#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
	string s1,s2;
	vector < char >::iterator it;
	int i = 1;
	while (!cin.eof())
	{
		cin >> s1 >> s2;
		vector < char > s;
		int k1 = s1.length();
		int k2 = s2.length();
		string::iterator it1;
		if(k1 < k2)
		{
			//cout << "hello\n";
			for (int i = 0; i < s1.length();i++)
			{
				size_t found;
				found = s2.find(s1[i]);
				if (found != string::npos)
				{
					s.push_back(s1[i]);
					it1 = s2.begin() + (int)found;
					s2.erase(it1);
				}
			}
		}
		else
		{
			//cout << "hii\n";
			for (int i = 0; i < s2.length(); i++)
			{
				size_t found;
				found = s1.find(s2[i]);
				if (found != string::npos)
				{
					s.push_back(s2[i]);
					it1 = s1.begin() + int(found);
					s1.erase(it1);
				}
				
			}
		}
		sort(s.begin(),s.end());
		for (it = s.begin(); it != s.end(); it++)
			cout << *it;
		cout << "\n";
		s.clear();
	}
	return 0;
}
