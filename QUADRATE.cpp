#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		//cin.ignore();
		string s;
		//getline(cin,s);
		cin >> s;
		int a = 1, b = 1, c = 0;
		size_t c_1,c_2,c_3;
		c_1 = s.find ("x*x",0);
		if (c_1 != 0)
		{
			int temp = 0;
			for (int i = 0; i < c_1 - 1; i++)
			{
				temp = 10*temp + s[i] - '0';
			}
				a = temp;
		}
		c_2 = s.find("x",c_1+3);
		if (c_2 == string::npos)
			b = 0;
		else
		{
			int sign;
			int temp = 0;
			if (s[c_1+3] == '-')
				sign = -1;
			else
				sign = 1;
			for (int i = c_1+4; i < c_2; i++)
			{
				if (s[i] >= '0' and s[i] <= '9')
					temp = temp*10 + s[i] - '0';
			}
			if (temp != 0)
			{
				b = temp*sign;
			}
			else
				b = sign;
		}
		c_3 = s.find("=",0);
		int ret = 0, tmp = 1,cnt = c_3-1;
		for(cnt=c_3-1;s[cnt]>='0' && s[cnt]<='9';cnt--)
		{
			ret=ret+(s[cnt]-'0')*tmp;
			tmp*=10;
		}
		if(s[cnt]=='-')
			c-= ret;
		else
			c = ret;
		int d = b*b - 4*a*c;
		//cout << a << ":" << b << ":" << c << "\n";
		if (d == 0)
			printf ("Equal roots.\n");
		else if (d > 0)
			printf ("Distinct real roots.\n");
		else
			printf ("Imaginary roots.\n");
	}
	return 0;
}
