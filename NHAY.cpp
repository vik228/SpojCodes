#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int l;
	while (scanf ("%d",&l) != EOF)
	{
		string s1,s2;
		cin >> s1 >> s2;
		size_t found;
		found = s2.find(s1);
		bool val = false;
		while (found != string::npos)
		{
			val = true;
			printf ("%d\n",(int)found);
			found = s2.find(s1,found + 1);
			//printf ("%d\n",(int)found);
		}
		if (!val)
			printf ("\n");
	}
	return 0;
}



