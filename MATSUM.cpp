#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
using namespace std;
#define MAX 2000
int bit[MAX][MAX];
void update (int x, int y, int n, int val)
{
	int y1;
	while (x <= n)
	{
		y1 = y;
		while (y1 <= n)
		{
			bit[x][y1] += val;
			y1 += (y1 & -y1); 
		}
		x += (x & -x); 
	}

}
int readSum(int x, int y)
{
	int v = 0, y1;
	while(x > 0)
	{
		y1 = y;
		while(y1 > 0)
		{
			v += bit[x][y1];
			y1 -= (y1 & -y1);
		}
		x -= (x & -x);
	}
	return v;
}
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		memset (bit, 0, sizeof (bit));
		int n;
		scanf ("%d",&n);
		char s1[5];
		while (scanf ("%s",&s1) == 1)
		{
			//cout << s1 << " ";
			//cout << "\n";
			//cout << s << "\n";
			if (!strcmp (s1, "END"))
				break;
			if (!strcmp (s1, "SET"))
			{
				int x, y, val;
				scanf ("%d%d%d",&x,&y,&val);
				//cout << x << ":" << y << "\n";
				x += 1;
				y += 1;
				int a = readSum (x, y);
				int b = readSum (x-1, y);
				int c = readSum (x, y-1);
				int d = readSum (x-1, y-1);
				int val1 = a - b - c + d;
				//cout << a << " " << b << " " << c << " " << d << "\n";

				update (x, y, n, val - val1);
				
			}
			else if (!strcmp (s1, "SUM"))
			{
				int x1, y1, x2, y2;
				scanf ("%d%d%d%d",&x1, &y1, &x2, &y2);
				x1 += 1;
				x2 += 1;
				y1 += 1;
				y2 += 1;
				int a = readSum (x2, y2);
				int b = readSum (x2, y1-1);
				int c = readSum (x1-1, y2);
				int d = readSum (x1-1, y1-1);
				//cout << a << " " << b << " " << c << " " << d << "\n";
				int sum = a - b - c + d;
				printf ("%d\n",sum);
			}
			//scanf ("%s",&s1);
		}
	}
	return 0;
}
