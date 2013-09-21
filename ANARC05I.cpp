#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 2002
int plane[MAX][MAX];
using namespace std;
int main()
{
	
	string s;
	while (cin >> s)
	{
		//cout << s << "\n";
		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
				plane[i][j] = 0;
		}
		int x = 1001, y = 1001;
		plane[x][y] = 1;
		int cnt = 0;
		if (s == "Q")
			break;
		for (int i = 0; s[i] != 'Q'; i++)
		{
			//cout << "hii\n";
			if (s[i] == 'U')
				y++;
			else if (s[i] == 'D')
				y--;
			else if (s[i] == 'R')
				x++;
			else if (s[i] == 'L')
				x--;
			//cout << x << " " << y << "\n";
			if (plane[x][y] == 1)
				cnt++;
			else
				plane[x][y] = 1;

		}
		printf ("%d\n",cnt);
		
	}
	return 0;
}
